books = input()

l_count = books.count ("L")
m_count = books.count ("M")
s_count = books.count ("S")

l_section = books [0 : l_count]
m_section = books [l_count : l_count + m_count]
s_section = books [l_count + m_count : l_count + m_count + s_count]

l_in_m = m_section.count ("L")
m_in_l = l_section.count ("M")
m_l_swaps = min (l_in_m, m_in_l)

misplaced_l = l_in_m + s_section.count ("L")
misplaced_m = m_in_l + s_section.count ("M")

answer = misplaced_l + misplaced_m - m_l_swaps
print (answer)
