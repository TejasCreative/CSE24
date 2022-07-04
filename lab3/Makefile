# =====================================
#   Lab 3 Makefile
#   Angelo Kyrilov
#   University of California, Merced
# =====================================

all:
	g++ -I. demo.cpp -o demo
	g++ -I. tipcalc.cpp -o tipcalc
	g++ -I. circ_area.cpp -o circ_area
	g++ -I. div.cpp -o div
	g++ -I. cut.cpp -o cut

demo: demo.cpp string_utils.h math_utils.h
	g++ -I. demo.cpp -o demo

tipcalc: tipcalc.cpp string_utils.h math_utils.h
	g++ -I. tipcalc.cpp -o tipcalc

circ_area: circ_area.cpp string_utils.h math_utils.h
	g++ -I. circ_area.cpp -o circ_area

div: div.cpp string_utils.h math_utils.h
	g++ -I. div.cpp -o div

cut: cut.cpp string_utils.h math_utils.h
	g++ -I. cut.cpp -o cut


.PHONY: test_tipcalc test_circ_area test_div test_cut test_all

test_tipcalc: test_tipcalc.cpp math_utils.h string_utils.h
	g++ -I. test_tipcalc.cpp -o test_tipcalc
	clear && echo "Testing Tip Calculator:" && ./test_tipcalc --output=color

test_circ_area: test_circ_area.cpp math_utils.h string_utils.h
	g++ -I. test_circ_area.cpp -o test_circ_area
	clear && echo "Testing Circle Area:" && ./test_circ_area --output=color

test_div: test_div.cpp math_utils.h string_utils.h
	g++ -I. test_div.cpp -o test_div
	clear && echo "Testing Integer Division Formatting:" && ./test_div --output=color

test_cut: test_cut.cpp math_utils.h string_utils.h
	g++ -I. test_cut.cpp -o test_cut
	clear && echo "Testing String Cutting:" && ./test_cut --output=color

test_all: test_all.cpp math_utils.h string_utils.h
	g++ -I. test_all.cpp -o test_all
	clear && echo "Testing All Functions:" && ./test_all --output=color

clean:
	rm -f demo
	rm -f tipcalc
	rm -f circ_area
	rm -f div
	rm -f cut
	rm -f test_tipcalc
	rm -f test_circ_area
	rm -f test_div
	rm -f test_cut
	rm -f test_all
