.data
userPrompt:     .asciiz "Enter your choice (0 for Rock, 1 for Paper, 2 for Scissors): "
compPrompt:     .asciiz "Computer's choice: "
playerWin:      .asciiz "You win!\n"
computerWin:    .asciiz "Computer wins!\n"
draw:           .asciiz "It's a draw!\n"
rock:           .asciiz "Rock\n"
paper:          .asciiz "Paper\n"
scissors:       .asciiz "Scissors\n"
playAgain:      .asciiz "Play again? (0 for No, 1 for Yes): "

.text
.globl main

main:
    loop:
        # Prompt the user for input
        li $v0, 4                   # system call for print_string
        la $a0, userPrompt          # load address of userPrompt string
        syscall                     # print the prompt

        # Read user input (0 for Rock, 1 for Paper, 2 for Scissors)
        li $v0, 5                   # system call for read_int
        syscall                     # read an integer from user
        move $t0, $v0               # store user choice in $t0

        # Generate computer's choice (0 for Rock, 1 for Paper, 2 for Scissors)
        li $v0, 42                  # system call for random integer
        li $a1, 3                   # range (0, 1, 2)
        syscall                     # generate random number
        move $t1, $a0               # store computer's choice in $t1

        # Print computer's choice prompt
        li $v0, 4                   # system call for print_string
        la $a0, compPrompt          # load address of compPrompt string
        syscall                     # print the prompt

        # Print computer's choice
        beq $t1, 0, print_rock      # if computer chose Rock
        beq $t1, 1, print_paper     # if computer chose Paper
        j print_scissors             # else, computer chose Scissors

        # Determine the winner
        beq $t0, $t1, draw_result   # if user and computer choices are equal, it's a draw
        beq $t0, 0, check_rock      # if user chooses Rock, check cases
        beq $t0, 1, check_paper     # if user chooses Paper, check cases
        j check_scissors             # else, user chooses Scissors

    check_rock:
        beq $t1, 2, player_win      # if computer chooses Scissors, player wins
        j computer_win              # else, computer wins

    check_paper:
        beq $t1, 0, player_win      # if computer chooses Rock, player wins
        j computer_win              # else, computer wins

    check_scissors:
        beq $t1, 1, player_win      # if computer chooses Paper, player wins
        j computer_win              # else, computer wins

    player_win:
        li $v0, 4                   # system call for print_string
        la $a0, playerWin           # load address of playerWin string
        syscall                     # print the string
        j play_again                # jump to play_again

    computer_win:
        li $v0, 4                   # system call for print_string
        la $a0, computerWin         # load address of computerWin string
        syscall                     # print the string
        j play_again                # jump to play_again

    draw_result:
        li $v0, 4                   # system call for print_string
        la $a0, draw                # load address of draw string
        syscall                     # print the string
        j play_again                # jump to play_again

    print_rock:
        li $v0, 4                   # system call for print_string
        la $a0, rock                # load address of rock string
        syscall                     # print the string
        j check_winner              # jump to check_winner

    print_paper:
        li $v0, 4                   # system call for print_string
        la $a0, paper               # load address of paper string
        syscall                     # print the string
        j check_winner              # jump to check_winner

    print_scissors:
        li $v0, 4                   # system call for print_string
        la $a0, scissors            # load address of scissors string
        syscall                     # print the string
        j check_winner              # jump to check_winner

    check_winner:
        beq $t0, $t1, draw_result   # if user and computer choices are equal, it's a draw
        beq $t0, 0, check_rock      # if user chooses Rock, check cases
        beq $t0, 1, check_paper     # if user chooses Paper, check cases
        j check_scissors             # else, user chooses Scissors

    play_again:
        # Prompt the user to play again
        li $v0, 4                   # system call for print_string
        la $a0, playAgain           # load address of playAgain string
        syscall                     # print the prompt

        # Read user input (0 for No, 1 for Yes)
        li $v0, 5                   # system call for read_int
        syscall                     # read an integer from user
        move $t2, $v0               # store user choice in $t2

        beq $t2, 1, loop            # if user chooses 1 (Yes), loop back to the beginning
        # else, exit the program

    exit:
        li $v0, 10                  # system call for exit
        syscall                     # exit the program