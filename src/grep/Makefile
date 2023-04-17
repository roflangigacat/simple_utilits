CC = gcc -std=c11
CFLAGS = -Wall -Werror -Wextra -D_GNU_SOURCE
GREP_FILES = grep.c
GREP_OBJ = $(GREP_FILES:.c=.o)
GREP_EXEC = ./grep
TESTS = tests/

OS = $(shell uname)
ifeq ($(OS), Darwin)
LEAK_CHECK =
endif
ifeq ($(OS), Linux)
LEAK_CHECK = valgrind --leak-check=full -s -q 
endif

all: build

build: grep

rebuild: clean build

grep:
	$(CC) $(CFLAGS) $(GREP_FILES) -o $(GREP_EXEC)

check: clean grep_test


# grep_test: grep_check
# 	bash grep_test_script.sh '$(LEAK_CHECK)' $(GREP_EXEC) $(TESTS) "[a-z]" grep_test_reg.txt 'log.txt' Makefile ../../README.md

grep_test: 
	($(LEAK_CHECK)$(GREP_EXEC) "[a-z]" Makefile ../../README.md > $(TESTS)grep_test.txt)
	grep "[a-z]" Makefile ../../README.md > $(TESTS)grep_test.txt
	($(LEAK_CHECK)$(GREP_EXEC) -e "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_e.txt)
	grep -e "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_e.txt
	($(LEAK_CHECK)$(GREP_EXEC) -i "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_i.txt)
	grep -i "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_i.txt
	($(LEAK_CHECK)$(GREP_EXEC) -v "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_v.txt)
	grep -v "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_v.txt
	($(LEAK_CHECK)$(GREP_EXEC) -c "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_c.txt)
	grep -c "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_c.txt
	($(LEAK_CHECK)$(GREP_EXEC) -l "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_l.txt)
	grep -l "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_l.txt
	($(LEAK_CHECK)$(GREP_EXEC) -n "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_n.txt)
	grep -n "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_n.txt
	($(LEAK_CHECK)$(GREP_EXEC) -h "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_h.txt)
	grep -h "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_h.txt
	($(LEAK_CHECK)$(GREP_EXEC) -s "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_s.txt)
	grep -s "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_s.txt
	($(LEAK_CHECK)$(GREP_EXEC) -f grep_test_reg.txt Makefile ../../README.md > $(TESTS)grep_test_f.txt)
	grep -f grep_test_reg.txt Makefile ../../README.md > $(TESTS)grep_test_f.txt
	($(LEAK_CHECK)$(GREP_EXEC) -o "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_o.txt)
	grep -o "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_o.txt
# Pair flags
	($(LEAK_CHECK)$(GREP_EXEC) -ie "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ie.txt)
	grep -ie "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ie.txt
	($(LEAK_CHECK)$(GREP_EXEC) -iv "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_iv.txt)
	grep -iv "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_iv.txt
	($(LEAK_CHECK)$(GREP_EXEC) -ic "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ic.txt)
	grep -ic "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ic.txt
	($(LEAK_CHECK)$(GREP_EXEC) -in "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_in.txt)
	grep -in "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_in.txt
	($(LEAK_CHECK)$(GREP_EXEC) -il "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_il.txt)
	grep -il "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_il.txt
	($(LEAK_CHECK)$(GREP_EXEC) -ih "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ih.txt)
	grep -ih "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ih.txt
	($(LEAK_CHECK)$(GREP_EXEC) -is "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_is.txt)
	grep -is "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_is.txt
	($(LEAK_CHECK)$(GREP_EXEC) -io "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_io.txt)
	grep -io "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_io.txt
	($(LEAK_CHECK)$(GREP_EXEC) -vc "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_vc.txt)
	grep -vc "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_vc.txt
	($(LEAK_CHECK)$(GREP_EXEC) -vl "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_vl.txt)
	grep -vl "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_vl.txt
	($(LEAK_CHECK)$(GREP_EXEC) -vn "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_vn.txt)
	grep -vn "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_vn.txt
	($(LEAK_CHECK)$(GREP_EXEC) -vh "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_vh.txt)
	grep -vh "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_vh.txt
	($(LEAK_CHECK)$(GREP_EXEC) -vs "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_vs.txt)
	grep -vs "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_vs.txt
	($(LEAK_CHECK)$(GREP_EXEC) -vo "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_vo.txt)
	grep -vo "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_vo.txt
	($(LEAK_CHECK)$(GREP_EXEC) -ci "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ci.txt)
	grep -ci "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ci.txt
	($(LEAK_CHECK)$(GREP_EXEC) -cv "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_cv.txt)
	grep -cv "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_cv.txt
	($(LEAK_CHECK)$(GREP_EXEC) -cn "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_cn.txt)
	grep -cn "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_cn.txt
	($(LEAK_CHECK)$(GREP_EXEC) -ch "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ch.txt)
	grep -ch "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ch.txt
	($(LEAK_CHECK)$(GREP_EXEC) -cs "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_cs.txt)
	grep -cs "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_cs.txt
	($(LEAK_CHECK)$(GREP_EXEC) -co "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_co.txt)
	grep -co "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_co.txt
	($(LEAK_CHECK)$(GREP_EXEC) -lv "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_lv.txt)
	grep -lv "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_lv.txt
	($(LEAK_CHECK)$(GREP_EXEC) -ln "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ln.txt)
	grep -ln "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ln.txt
	($(LEAK_CHECK)$(GREP_EXEC) -lh "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_lh.txt)
	grep -lh "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_lh.txt
	($(LEAK_CHECK)$(GREP_EXEC) -ls "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ls.txt)
	grep -ls "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ls.txt
	($(LEAK_CHECK)$(GREP_EXEC) -lo "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_lo.txt)
	grep -lo "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_lo.txt
	($(LEAK_CHECK)$(GREP_EXEC) -nh "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_nh.txt)
	grep -nh "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_nh.txt
	($(LEAK_CHECK)$(GREP_EXEC) -ns "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ns.txt)
	grep -ns "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ns.txt
	($(LEAK_CHECK)$(GREP_EXEC) -no "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_no.txt)
	grep -no "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_no.txt
	($(LEAK_CHECK)$(GREP_EXEC) -hn "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_hn.txt)
	grep -hn "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_hn.txt
	($(LEAK_CHECK)$(GREP_EXEC) -hs "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_hs.txt)
	grep -hs "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_hs.txt
	($(LEAK_CHECK)$(GREP_EXEC) -ho "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ho.txt)
	grep -ho "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ho.txt
	($(LEAK_CHECK)$(GREP_EXEC) -so "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_so.txt)
	grep -so "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_so.txt
	($(LEAK_CHECK)$(GREP_EXEC) -ve "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ve.txt)
	grep -ve "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ve.txt
	($(LEAK_CHECK)$(GREP_EXEC) -ce "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ce.txt)
	grep -ce "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_ce.txt
	($(LEAK_CHECK)$(GREP_EXEC) -le "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_le.txt)
	grep -le "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_le.txt
	($(LEAK_CHECK)$(GREP_EXEC) -he "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_he.txt)
	grep -he "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_he.txt
	($(LEAK_CHECK)$(GREP_EXEC) -se "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_se.txt)
	grep -se "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_se.txt
	($(LEAK_CHECK)$(GREP_EXEC) -oe "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_oe.txt)
	grep -oe "[a-z]" Makefile ../../README.md > $(TESTS)grep_test_oe.txt
	($(LEAK_CHECK)$(GREP_EXEC) -sf grep_test_reg.txt Makefile ../../README.md > $(TESTS)grep_test_sf.txt)
	grep -sf grep_test_reg.txt Makefile ../../README.md > $(TESTS)grep_test_sf.txt
	($(LEAK_CHECK)$(GREP_EXEC) -if grep_test_reg.txt Makefile ../../README.md > $(TESTS)grep_test_if.txt)
	grep -if grep_test_reg.txt Makefile ../../README.md > $(TESTS)grep_test_if.txt
	($(LEAK_CHECK)$(GREP_EXEC) -vf grep_test_reg.txt Makefile ../../README.md > $(TESTS)grep_test_vf.txt)
	grep -vf grep_test_reg.txt Makefile ../../README.md > $(TESTS)grep_test_vf.txt
	($(LEAK_CHECK)$(GREP_EXEC) -cf grep_test_reg.txt Makefile ../../README.md > $(TESTS)grep_test_cf.txt)
	grep -cf grep_test_reg.txt Makefile ../../README.md > $(TESTS)grep_test_cf.txt
	($(LEAK_CHECK)$(GREP_EXEC) -lf grep_test_reg.txt Makefile ../../README.md > $(TESTS)grep_test_lf.txt)
	grep -lf grep_test_reg.txt Makefile ../../README.md > $(TESTS)grep_test_lf.txt
	($(LEAK_CHECK)$(GREP_EXEC) -nf grep_test_reg.txt Makefile ../../README.md > $(TESTS)grep_test_nf.txt)
	grep -nf grep_test_reg.txt Makefile ../../README.md > $(TESTS)grep_test_nf.txt
	($(LEAK_CHECK)$(GREP_EXEC) -hf grep_test_reg.txt Makefile ../../README.md > $(TESTS)grep_test_hf.txt)
	grep -hf grep_test_reg.txt Makefile ../../README.md > $(TESTS)grep_test_hf.txt
	($(LEAK_CHECK)$(GREP_EXEC) -of grep_test_reg.txt Makefile ../../README.md > $(TESTS)grep_test_of.txt)
	grep -of grep_test_reg.txt Makefile ../../README.md > $(TESTS)grep_test_of.txt
	
# File comparsions
	diff $(TESTS)grep_test.txt $(TESTS)grep_test.txt
	diff $(TESTS)grep_test.txt $(TESTS)grep_test.txt
	diff $(TESTS)grep_test_e.txt $(TESTS)grep_test_e.txt
	diff $(TESTS)grep_test_i.txt $(TESTS)grep_test_i.txt
	diff $(TESTS)grep_test_v.txt $(TESTS)grep_test_v.txt
	diff $(TESTS)grep_test_c.txt $(TESTS)grep_test_c.txt
	diff $(TESTS)grep_test_l.txt $(TESTS)grep_test_l.txt
	diff $(TESTS)grep_test_n.txt $(TESTS)grep_test_n.txt
	diff $(TESTS)grep_test_h.txt $(TESTS)grep_test_h.txt
	diff $(TESTS)grep_test_s.txt $(TESTS)grep_test_s.txt
	diff $(TESTS)grep_test_f.txt $(TESTS)grep_test_f.txt
	diff $(TESTS)grep_test_o.txt $(TESTS)grep_test_o.txt
	diff $(TESTS)grep_test_ie.txt $(TESTS)grep_test_ie.txt
	diff $(TESTS)grep_test_iv.txt $(TESTS)grep_test_iv.txt
	diff $(TESTS)grep_test_ic.txt $(TESTS)grep_test_ic.txt
	diff $(TESTS)grep_test_in.txt $(TESTS)grep_test_in.txt
	diff $(TESTS)grep_test_nf.txt $(TESTS)grep_test_nf.txt
	diff $(TESTS)grep_test_no.txt $(TESTS)grep_test_no.txt
	diff $(TESTS)grep_test_il.txt $(TESTS)grep_test_il.txt
	diff $(TESTS)grep_test_ih.txt $(TESTS)grep_test_ih.txt
	diff $(TESTS)grep_test_is.txt $(TESTS)grep_test_is.txt
	diff $(TESTS)grep_test_io.txt $(TESTS)grep_test_io.txt
	diff $(TESTS)grep_test_vc.txt $(TESTS)grep_test_vc.txt
	diff $(TESTS)grep_test_vl.txt $(TESTS)grep_test_vl.txt
	diff $(TESTS)grep_test_vn.txt $(TESTS)grep_test_vn.txt
	diff $(TESTS)grep_test_vh.txt $(TESTS)grep_test_vh.txt
	diff $(TESTS)grep_test_vs.txt $(TESTS)grep_test_vs.txt
	diff $(TESTS)grep_test_vo.txt $(TESTS)grep_test_vo.txt
	diff $(TESTS)grep_test_ci.txt $(TESTS)grep_test_ci.txt
	diff $(TESTS)grep_test_cv.txt $(TESTS)grep_test_cv.txt
	diff $(TESTS)grep_test_cn.txt $(TESTS)grep_test_cn.txt
	diff $(TESTS)grep_test_ch.txt $(TESTS)grep_test_ch.txt
	diff $(TESTS)grep_test_cs.txt $(TESTS)grep_test_cs.txt
	diff $(TESTS)grep_test_co.txt $(TESTS)grep_test_co.txt
	diff $(TESTS)grep_test_lv.txt $(TESTS)grep_test_lv.txt
	diff $(TESTS)grep_test_ln.txt $(TESTS)grep_test_ln.txt
	diff $(TESTS)grep_test_lh.txt $(TESTS)grep_test_lh.txt
	diff $(TESTS)grep_test_ls.txt $(TESTS)grep_test_ls.txt
	diff $(TESTS)grep_test_lo.txt $(TESTS)grep_test_lo.txt
	diff $(TESTS)grep_test_nh.txt $(TESTS)grep_test_nh.txt
	diff $(TESTS)grep_test_ns.txt $(TESTS)grep_test_ns.txt
	diff $(TESTS)grep_test_no.txt $(TESTS)grep_test_no.txt
	diff $(TESTS)grep_test_hn.txt $(TESTS)grep_test_hn.txt
	diff $(TESTS)grep_test_hs.txt $(TESTS)grep_test_hs.txt
	diff $(TESTS)grep_test_ho.txt $(TESTS)grep_test_ho.txt
	diff $(TESTS)grep_test_so.txt $(TESTS)grep_test_so.txt
	diff $(TESTS)grep_test_ve.txt $(TESTS)grep_test_ve.txt
	diff $(TESTS)grep_test_ce.txt $(TESTS)grep_test_ce.txt
	diff $(TESTS)grep_test_le.txt $(TESTS)grep_test_le.txt
	diff $(TESTS)grep_test_he.txt $(TESTS)grep_test_he.txt
	diff $(TESTS)grep_test_se.txt $(TESTS)grep_test_se.txt
	diff $(TESTS)grep_test_oe.txt $(TESTS)grep_test_oe.txt
	diff $(TESTS)grep_test_sf.txt $(TESTS)grep_test_sf.txt
	diff $(TESTS)grep_test_if.txt $(TESTS)grep_test_if.txt
	diff $(TESTS)grep_test_vf.txt $(TESTS)grep_test_vf.txt
	diff $(TESTS)grep_test_cf.txt $(TESTS)grep_test_cf.txt
	diff $(TESTS)grep_test_lf.txt $(TESTS)grep_test_lf.txt
	diff $(TESTS)grep_test_nf.txt $(TESTS)grep_test_nf.txt
	diff $(TESTS)grep_test_hf.txt $(TESTS)grep_test_hf.txt
	diff $(TESTS)grep_test_of.txt $(TESTS)grep_test_of.txt

clean:
	rm -rf $(TESTS)*.txt
	rm -rf *.o *.gch
	rm -rf *.dSYM
	rm -rf $(COMMON_PATH)*.o
	rm -rf grep
	rm -rf *.out

