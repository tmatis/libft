#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
BOLD='\033[1m'
NC='\033[0m'

OBJS=$@

FILES=$(find tests -name "*.c")
FILES_INLINE=$(echo $FILES | sed 's/\n/ /g')

script_dir=libft/scripts
libft_dir=libft

if [ "$LIBFT_TEST" = "true" ]; then
    script_dir=scripts
    libft_dir=.
fi


function cleanup {
    rm -f .tests
    rm -f .test_main.c
    rm -f .Makefile-tests
    rm -f .compilation_output
}

echo -en "${CYAN}Generating test files... ${NC}"

echo -e "#include <ft_test.h>\n\nTEST_FRAMEWORK" > .test_main.c
sed "s|{{srcs}}|$FILES_INLINE|g" $script_dir/templates/tests/Makefile.template | sed "s|{{objs}}|$OBJS|g" > .Makefile-tests

echo -e "${GREEN}[OK]${NC}"

echo -en "${CYAN}Compiling test files... ${NC}"

make -f .Makefile-tests LIBFTDIR=$libft_dir &> .compilation_output
if [ $? -ne 0 ]; then
    echo -e "${RED}[KO]${NC}"
    echo -e "${RED}Compilation failed!${NC}"
    cat .compilation_output
    cleanup
    exit 1
fi
echo -e "${GREEN}[OK]${NC}"

echo -e "${CYAN}Running tests... ${NC}\n"
./.tests
if [ $? -ne 0 ]; then
    cleanup
    exit 1
fi
cleanup
exit 0





