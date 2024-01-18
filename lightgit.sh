#!/bin/bash

GREY='\033[1;30m'
LGREY='\033[0;30m'
RED='\033[1;31m'
LRED='\033[0;31m'
GREEN='\033[1;32m'
LGREEN='\033[0;32m'
YELLOW='\033[1;33m'
LYELLOW='\033[0;33m'
BOLD='\033[1;37m'
NC='\033[0m'
SWAG='🫠'

function showStatus() {
	staged_files=$(git status -s | grep -E '^[AM]' | awk '{print $2}' | tr '\n' ' ')
	untracked_files=$(git status -s | grep -E '^\?\?|^ M' | awk '{print $2}' | tr '\n' ' ')
	echo -e "\n${BOLD}SUMMARY:${NC}"
	if [ -z "$staged_files" ]; then
		echo -e "${GREEN}Tracked files:\t ${LGREY}none${NC}"
		echo -e "${LGREEN}Untracked files: ${NC}$untracked_files"
	elif [ -z "$untracked_files" ]; then
		echo -e "${GREEN}Tracked files:\t ${NC}$staged_files"
		echo -e "${LGREEN}Untracked files: ${LGREY}none${NC}"
	else
		echo -e "${GREEN}Tracked files:\t ${NC}$staged_files"
		echo -e "${LGREEN}Untracked files: ${NC}$untracked_files"
	fi
	echo -e "${GREEN}Commit message:\t${NC} $commit"
}

function handleAction() {
	while [[ "$action" != "p" && "$action" != "c" && "$action" != "a" ]]; do
		read -p $'\e[1;31m\npush, commit or abort [p/c/a]:\e[0m' -n 1 -a action
	done
	echo ""
	if [ "$action" == "p" ]; then
		echo -e "\n${GREEN}Committing...${NC}"
		git commit -m "$commit"
		read -e -p $'\n\e[0;32mgit push \e[0m' -a remote
		echo -e "\n${GREEN}Pushing...${NC}"
		git push $remote
		if [ $? -eq 0 ]; then
			echo -e "\n${GREEN}REPO PUSH COMPLETED $SWAG${NC}"
		fi
	elif [ "$action" == "c" ]; then
		echo -e "\n${GREEN}Committing...${NC}"
		git commit -m "$commit"
	elif [ "$action" == "a" ]; then
		echo -e "\n${LRED}Push aborted. Resetting files off staging area.${NC}"
		git reset $files &> /dev/null
	fi
}

function quickMode() {
	read -e -p $'\e[0;32mgit add \e[0m' -a files
	for file in "${files[@]}"; do
		if git add "$file" &> /dev/null; then
			git add "$file"
		else
			echo -e "${RED}'$file' ${LRED}did not match any files${NC}"
		fi
	done
	while [ -z "$commit" ]; do
		read -e -p $'\e[0;32mcommit message: \e[0m' commit
		if [ -z "$commit" ]; then
			echo -e "${LRED}Please enter a commit message.${NC}"
		fi
	done
	showStatus
	handleAction
}


function normalMode() {
	# welcome to lightgit
	echo -e "\nPlease enter the files or directories to add separated by a space, or '.' to add all files."
	read -e -p $'\e[0;32mFiles to add: \e[0m' files 
	#same as above but with terminal completion

    echo -e "\n${LGREEN}Adding ${#files[@]} files to staging area:${NC}"
    for file in "${files[@]}"; do
        if git add "$file" &> /dev/null; then
			git add "$file"
        	echo -e "'$file' added$"
		else
			echo -e "${RED}'$file' ${LRED}did not match any files${NC}"
		fi
    done
	showStatus
	handleAction
}

setlgit() {
    echo -e "${LGREEN}Setting up 'lgit' alias...${NC}"
    if [ "$(echo $SHELL)" = "/bin/bash" ]; then
		if [ -z "$(grep "^alias lgit=" ~/.zshrc)" ]; then
        	echo -e "alias lgit=\"$PWD/lightgit.sh\" \"\$@\"" >> ~/.bashrc
        	source ~/.bashrc
        	echo -e "${GREEN}Alias 'lgit' set up successfully in ~/.bashrc.${NC}"
		else
			echo -e "${LRED}Alias 'lgit' already exists in ~/.bashrc.${NC}"
		fi
    elif [ "$(echo $SHELL)" = "/bin/zsh" ]; then
        if [ -z "$(grep "^alias lgit=" ~/.zshrc)" ]; then
			echo -e "alias lgit=\"$PWD/lightgit.sh\" \"\$@\"" >> ~/.zshrc
        	source ~/.zshrc
        	echo -e "${BOLD}Alias 'lgit' written successfully in ~/.zshrc.${NC}"
        	echo -e "If you use ohmyzsh, please run ${BOLD}'source ~/.zshrc'${NC} to finish the installation."
		else
			echo -e "${LRED}Alias 'lgit' already exists in ~/.zshrc.${NC}"
		fi
    else
        echo -e "${LRED}Could not set up alias 'lgit': please use ./lightgit.sh instead.${NC}"
        echo $0
    fi
}

help() {
	echo -e "${BOLD}┌─────────────────────────────────────────────────────────────┐${NC}"
	echo -e "${BOLD}│ LIGHTGIT.SH - a single command for git add, commit and push │${NC}"
	echo -e "${BOLD}└─────────────────────────────────────────────────────────────┘${NC}\n"
	echo -e "${BOLD}LGIT COMMAND SETUP:\t${NC}./lightgit.sh setlgit  ${LGREY}-> creates the alias 'lgit' for './lightgit'${NC}\n"
    echo -e "${BOLD}MODES:\t\t\t${NC}lgit n ${LGREY}-> normal mode, shows processes in detail.${NC}"
    echo -e "${BOLD}\t\t\t${NC}lgit q ${LGREY}-> quick mode, only necessary infos.${NC}\n"
}

if [ $# -eq 0 ]; then
    echo -e "${LRED}Missing mode argument.${NC}"
	echo -e "${BOLD}First time using LIGHTGIT?${NC} Try ${BOLD}./lightgit.sh help${NC} for manual."
    exit 1
fi

if [ "$1" == "setlgit" ]; then
	setlgit
elif [ "$1" == "help" ] || [ "$1" == "h" ] || [ "$1" == "man" ]; then
	help
elif [ "$1" == "n" ]; then
	normalMode
elif [ "$1" == "q" ]; then
	quickMode
else
	echo -e "${LRED}Invalid mode argument."
	exit 1
fi

