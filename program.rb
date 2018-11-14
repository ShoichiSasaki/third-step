require "numo/narray"
include Numo

sci_score = Numo::DFloat[65,80,67,35,58,60,72,75,68,92,36,50,2,58.5,46,42,78,62,84,70]
eng_score = Numo::DFloat[44,87,100,63,52,60,58,73,55,86,29,56,89,23,65,84,64,27,86,84]

puts('理科')
print(' 平均点  ')
puts(sci_score.mean)
print(' 標準偏差  ')
puts(sci_score.stddev)
print(' 合計点')
puts(sci_score.sum)

puts('英語')
print(' 平均点 　')
puts(eng_score.mean)
print(' 標準偏差 　')
puts(eng_score.stddev)
print(' 合計点　　')
puts(eng_score.sum)

puts('理科　偏差値')
sci_score.each{|score|
	puts((10.0*(score - sci_score.mean) / sci_score.stddev) +50.0)
}
puts('英語　偏差値')
eng_score.each{|score|
	puts((10.0*(score - eng_score.mean) / eng_score.stddev) +50.0)
}

puts('理科　高い順番')
sci_score.sort.reverse.each{|score|
	puts(score)
}

puts('英語　高い順番')
eng_score.sort.reverse.each{|score|
	puts(score)
}