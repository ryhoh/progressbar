# 堀哲也 2016/11/05
# Copyright (c) 2016 Tetsuya Hori
# Released under the MIT license
# https://opensource.org/licenses/mit-license.php


# 		pos		完了した作業工程の数
# 		full	全作業工程の数
#
#		入力されるposは常に		0 <= pos <= full	を満たす
#		表示成功で0、失敗で1を返す
#
#
#		表示例	（全工程1000個中、334個完了の状態）
#
#		|******--------------| 33.4%    NUM:[ 334 / 1000 ]
#
#		表示部は20文字からなる21段階で、5%完了する毎に*が追加される
#		百分率は右詰め5桁（.以下1桁）表記、空きは空白で埋める

# 正常終了でTrue、異常発生でFalseを返す
def normal(pos, full):
	# posが0-fullの間であることを確かめる
	if pos < 0 or full < pos:
		print("progress bar error")
		return False
	
	# 21段階のプログレスバーを表示するにあたって、fullに対するposの割合を0から20の21段階で表したい
	bar = int(pos / full * 20)
	
	# 表示
	print("|{0}{1}| {2:5.1f}%    NUM:[{3} / {4} ]".format("*" * bar, "-" * (20-bar), pos / full * 100, pos, full))
	return True

def simple(pos, full):
	# posが0-fullの間であることを確かめる
	if pos < 0 or full < pos:
		print("progress bar error")
		return False
	
	# 21段階のプログレスバーを表示するにあたって、fullに対するposの割合を0から20の21段階で表したい
	bar = int(pos / full * 20)
	
	# 表示
	print("|{0}{1}| {2:5.1f}%".format("*" * bar, "-" * (20-bar), pos / full * 100))
	return True