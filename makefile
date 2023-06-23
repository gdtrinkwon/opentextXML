converter: XMLtoHTMLConverter.cpp table.o XMLParser.o
	g++ -o converter XMLtoHTMLConverter.cpp table.o XMLParser.o -Idependencies

XMLParser.o : XMLParser.cpp table.o
	g++ -c XMLParser.cpp -Idependencies

table.o : table.cpp table.h
	g++ -c table.cpp

clean:
	rm converter.exe XMLParser.o table.o