#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
BOLD='\033[1m'

if [ $# -eq 0 ]; then
    echo "Usage: $0 <project_name>"
    exit 1
fi

PROJECT_NAME=$1

echo -e "${CYAN}Generating project ${BOLD}$PROJECT_NAME${CYAN}...${NC}"

echo -e "${GREEN}Generating Makefile...${NC}"
sed "s/{{name}}/$PROJECT_NAME/g" libft/scripts/templates/Makefile.template > Makefile

echo -e "${GREEN}Generating file structure...${NC}"

mkdir -p includes
mkdir -p srcs
mkdir -p tests
mkdir -p scripts

echo -e "int main(void)\n{\n\treturn (0);\n}" > srcs/main.c

echo -e "${GREEN}Generating .gitignore...${NC}"

sed "s/{{name}}/$PROJECT_NAME/g" libft/scripts/templates/.gitignore.template > .gitignore

echo -e "${GREEN}Generating github pipeline...${NC}"

mkdir -p .github/workflows

sed "s/{{name}}/$PROJECT_NAME/g" libft/scripts/templates/test.yml.template > .github/workflows/test.yml
