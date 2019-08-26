from Verilog_VCD import *
import matplotlib.pyplot as plt

vcd = parse_vcd('hardgf2.vcd')

trans_count = [0] * (get_endtime() + 1)

signal_count = 0;
trans_sum = 0
for key in vcd.keys():
	signal_count += len(vcd[key]['nets'])
	trans_sum += len(vcd[key]['tv'])
	for trans in vcd[key]['tv']:
		try:
			trans_count[trans[0]] += 1
		except Exception as e:
			print(trans[0])

print(signal_count)
print(trans_sum)
print(sum(trans_count))

plt.plot(trans_count[1:])
plt.show()
