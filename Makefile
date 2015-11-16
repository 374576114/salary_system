objects = fileOperation.o InputPrint.o main.o Menu.o ModifyFuntion.o \
readPassword.o SummarySalary.o

salary:$(objects)
	cc -o salary $(objects)

$(objects):Salary.h

clean:
	rm salary $(objects)
