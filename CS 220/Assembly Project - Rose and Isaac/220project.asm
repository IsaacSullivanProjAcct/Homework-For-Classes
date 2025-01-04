# Set entry as main
.globl main

.data
# Employee IDs
# 16 bits, min 0, max 65535
eids: .word 1, 4, 19, 240, 564, 46641, 6888, 43534, 16989, 12602, 48381, 56703, 54094, 26643, 53314, 24920, 8362, 25825, 42408, 4648

# Passwords
# 8 bits, min 0, max 255
pwds: .word 189, 18, 12, 53, 75, 123, 212, 32, 92, 11, 53, 54, 91, 223, 154, 177, 244, 88, 67, 69

# Inputs
ineid: .word 240
inpwd: .word 53

# Layout
# s1: Input EID
# s2: Input PWD
# s3: current loop address
# s4: address offset of eid if found (640 if not in array)

.text
# Jump to main to avoid unwanted calls (because sometimes globl doesn't set entry point right)
j main

# End case where program outputs 0 and exits
exit:
	# Load 4 to v0 (syscall for print) and 0 to a0 (auxilary for syscall)
	li $v0, 1
	li $a0, 0
	syscall

	# Load 10 to v0 (syscall for exit execution)
	li $v0, 10
	syscall

success:
	# Load 4 to v0 (syscall for print) and 1 to a0 (auxilary for syscall)
	li $v0, 1
	li $a0, 1
	syscall

	# Load 10 to v0 (syscall for exit execution)
	li $v0, 10
	syscall

eid_matched:
	# Load from pwds with offset of s3 into t2.
	# We do this by loading the address of pwds to t4, adding s3 to it, and then loading t4 to t2
	li $t4, 0
	la $t4, pwds

	add $t4, $t4, $s3
	lw $t2, ($t4)

	# If s2 == t2, j success
	beq $s2, $t2, success

	# Else j exit
	j exit

# Loops through eids and checks for input eid. If found, jump eid_matched, else exit
find_eid:
	# Max loop offset in bytes
	li $t0, 80
	find_eid_loop:
	# If s3 >= 640, j exit
	bge $s3, $t0, exit

	# Load from eids with offset of s3 into t2.
	# We do this by loading the address of eids to t4, adding s3 to it, and then loading t4 to t2
	la $t4, eids
	add $t4, $t4, $s3
	lw $t2, ($t4)

	# If s1 == t2, j eid_matched
	beq $s1, $t2, eid_matched

	# Add 4 to s1 (length of word in bytes)
	addi $s3, 4

	# Jump start of loop
	j find_eid_loop

# Starting position, sets up inputs and jumps to find_eid
main:
	# $s1 = input eid
	# $s2 = input pwd
	# $s3 = loop offset
	lw $s1, ineid
	lw $s2, inpwd
	li $s3, 0
	j find_eid


# Debug print
#li $v0, 1
#add $a0, $t2, $zero
#syscall