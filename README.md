# fuzzy-logic-prototyping-with-c
Build a logical system that determines the classification and the quality of potable water using fuzzy logic as problem-solving technique.
This app that implemented is execute the decision mechanism algorithm (see rules table) by calculating specified parameters(CI, CaCo3 etc.) in the water.

Rules Table

1- 	fuzzyfication
2-  fuzzy inference
3-  clarification

### Structure
```shell
if (input1 is membersihp function1) and/or
   (input2 is membership function2) and/or.....
 
  Then (output is output membership function).

for example rule
	if temperature is high and humidity is high then room is hot.
```

### Rules
* if CaCo3 is SOFT and CI is GOOD then A,
* if CaCo3 is SOFT and CI is MEDIOCRE then A,
* if CaCo3 is SOFT and CI is BAD then B

* if CaCo3 is MEDIUM-HARD and CI is GOOD then A,
* if CaCo3 is MEDIUM-HARD and CI is MEDIOCRE then B,
* if CaCo3 is MEDIUM-HARD and CI is BAD then C

* if CaCo3 is HARD and CI is GOOD then B,
* if CaCo3 is HARD and CI is MEDIOCRE then C,
* if CaCo3 is HARD and CI is BAD then C
