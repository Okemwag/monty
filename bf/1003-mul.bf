read
>,	store value in cell 1
>,	store value in cell 2
<<	move to cell 0

convert from ascii
+++++ +	multiplier of 6
[
 >----- ---	cell 1 to 0
 >----- ---	cell 2 to 0
 <<-	return to cell 0
]

multiply
>	move to cell 1
[
	>	move to cell 2
	[>+>+<<-]    move cell 3 to 4
	>	move to cell 3
	[<+>-]	add cell 2 to cell 3
 	<<-	return to cell 1
]

separate numbers
>[-]>+> >+++++ +++++<
[
 - >- [>>>]+++++ +++++<<+
 [<<<]>>>>
]
<-
<+++++ +++++>>>[-<<<->>>]<<<


convert to ascii
<+++++ +
[
 >+++++ +++>
 [+++++ +++>]
 <[<]>-
]

print
>>[.<<]<[<<]>>.		tens place then ones place
>>>>>++++++++++.	print newline