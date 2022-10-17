import itertools
from operator import mul
from functools import reduce
import sys
from time import time
from math import floor


def satisfies_r(s, row, r):
	return satisfies_l(s, list(reversed(row)), r)


def satisfies_l(s, row, l):
	if len(set(row)) < s:
		return False
	if l == 0:
		return True
	seen = 0
	curr_max = 0
	for entry in row:
		if entry > curr_max:
			curr_max = entry
			seen += 1
			if entry == s or seen > l:
				break
	return l == seen


def possible_rows(s, l, r):
	p = []
	for row in itertools.permutations(range(1, s + 1)):
		if satisfies_l(s, row, l) and satisfies_r(s, row, r):
			p.append(list(row))
	return p


def format_time(s):
	sinm = 60
	sinh = 60 * sinm
	sind = 24 * sinh
	d = h = m = 0
	r = s
	if s > sind:
		d = floor(r / sind)
		r -= d * sind
	if s > sinh:
		h = floor(r / sinh)
		r -= h * sinh
	if s > sinm:
		m = floor(r / sinm)
		r -= m * sinm
	return f'{d}:{h:02d}:{m:02d}:{r:02d}'


def print_time(done, total, s):
	eta = format_time(int((total / done - 1) * s))
	print(
		f'progress: {done} / {total} = {done * 100 / total:.2f}%, est. max. time left: {eta}')


def print_time_found(done, total, s):
	dhms = format_time(int(s))
	print(
		f'Solution found after searching {done} / {total} = {done * 100 / total:.2f}% in {dhms}')


def is_valid_solution(s, solution, t, b):
	count = 0
	for i in range(s):
		c = [row[i] for row in solution]
		if not (satisfies_l(s, c, t[i]) and satisfies_r(s, c, b[i])):
			break
		count += 1
	return count == s


def solve(s, l, r, t, b, verbose):
	rows = [possible_rows(s, l[i], r[i]) for i in range(s)]
	sol_count = 0
	total = reduce(mul, [len(row) for row in rows], 1)
	first_time = time()
	prev_time = first_time
	start_freq = 10000
	time_freq = start_freq
	if verbose > 0:
		print(f'{total} possible solutions')
	for solution in itertools.product(*rows):
		sol_count += 1
		if verbose > 0 and sol_count % time_freq == 0:
			curr_time = time()
			if curr_time >= prev_time + verbose:
				if time_freq == start_freq:
					time_freq = sol_count / 10
				print_time(sol_count, total, curr_time - first_time)
				prev_time = curr_time
		if is_valid_solution(s, solution, t, b):
			if verbose > 0:
				print_time_found(sol_count, total, curr_time - first_time)
			return solution
	return ["no solution found"]


def main(argv):
	# s = 0
	# l = r = t = b = []
	# verbose = 0
	# for arg in argv[1:]:
	# 	if arg[0:2] == '-s':
	# 		s = int(arg[2:])
	# 		if s > 9:
	# 			print('size should be 9 or smaller')
	# 			exit()
	# 	if arg[0:2] == '-c':
	# 		temp = [int(i) for i in arg[2:]]
	# 		t = temp[0:s]
	# 		r = temp[s:2*s]
	# 		b = list(reversed(temp[2*s:3*s]))
	# 		l = list(reversed(temp[3*s:]))
	# 	if arg[0:2] == '-l':
	# 		l = [int(i) for i in arg[2:]]
	# 	if arg[0:2] == '-r':
	# 		r = [int(i) for i in arg[2:]]
	# 	if arg[0:2] == '-t':
	# 		t = [int(i) for i in arg[2:]]
	# 	if arg[0:2] == '-b':
	# 		b = [int(i) for i in arg[2:]]
	# 	if arg[0:2] == '-v':
	# 		verbose = 1
	# 		if len(arg) > 2:
	# 			verbose = float(arg[2:])
	# if verbose > 0:
	# 	print(s, l, r, t, b, verbose)
    s = 4
    l = [4, 3, 2, 1]
    r = [1, 2, 2, 2]
    t = [4, 3, 2, 1]
    b = [1, 2, 2, 2]
    verbose = 0
    for row in solve(s, l, r, t, b, verbose):
        print(row)


if __name__ == '__main__':
	main(sys.argv)
