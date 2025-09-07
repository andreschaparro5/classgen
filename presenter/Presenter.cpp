/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 */

#include "Presenter.h"
#include "../logic/FileManagement.h"
#include "../view/View.h"
#include <string>
#include <list>
#include <vector>
#include <cctype>

using namespace std;

void Presenter::start(){
	string name_class, data;
	int number_of_atributes, iterator;
	list<string> atributes, atributes_names;
	vector<string> types;
	
	View::colorTerm("Class Name: ", "red");
	cin >> name_class;
	View::colorTerm("Atributes number: ", "red");
	cin >> number_of_atributes;
	
	// Pidiendo los datos al usuario
	for(int i=0; i<number_of_atributes; i++){
		string type, atribute_name, line;
		cout << "Atribute [" << i+1 << "]: ";
		cin >> type;
		cin >> atribute_name;
		line = type + " " + atribute_name;
		
		types.push_back(type);
		atributes_names.push_back(atribute_name);
		atributes.push_back(line);
	}
	
	for(string value : atributes){
		View::colorTerm(value, "blue");
	}
	
	// Creando la clase
	data += "public class " + name_class + "{\n";
	
	// Atributos
	for(string atribute : atributes){
		data += "	private " + atribute + ";\n";
	}
	
	// Constructor
	data += "	\n	// builder\n";
	data+= "	public " + name_class + "(";
	
	for(string atribute : atributes){
		data += atribute + ", ";
	}
	data.erase(data.length() - 2);
	data += "){\n";
	
	for(string atribute : atributes_names){
		string aux = atribute;
		aux[0] = toupper(aux[0]);
		
		data += "		set" + aux;
		data += "(" + atribute + ");\n";
	}
	
	data += "\n	}\n";
	
	iterator = 0;
	data += "\n 	// Getters\n";
	
	// Getters
	for(string atribute : atributes_names){
		string aux = atribute;
		aux[0] = toupper(aux[0]);
		
		data += "	public " + types[iterator] + " get";
		data += aux;
		data += "(){\n";
		data += "		return " + atribute + ";\n";
		data += "	}\n";
		iterator++;
	}
	
	data += "\n 	// Setters\n";
	iterator = 0;
	
	// Setters
	for(string atribute : atributes_names){
		string aux = atribute;
		aux[0] = toupper(aux[0]);
		
		data += "	public void set";
		data += aux; 
		data += "(" + types[iterator] + " " + atribute + "){\n";
		data += "		this." + atribute + " = " + atribute + ";\n";
		data += "	}\n";
		iterator++;
	}
	
	// toString
	data += "\n	// toString\n";
	data += "	@Override \n";
	data += "	public String toString(){\n		return ";
	
	for(string atribute : atributes_names){
		string aux = atribute;
		aux[0] = toupper(aux[0]);
		data += "\"[" + aux + ": \" + " + atribute + "+\"],\"+\n				";
	}
	data.erase(data.length() - 6);
	data += ";\n	}\n";
	data += "}";
	
	FileManagement fm(name_class + ".java");
	fm.writeFile(data);
	View::colorTerm("Archivo creado con exito!!", "blue");
}

