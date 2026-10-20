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

#include "FileManagement.h"
#include <iostream>
// Para leer y escribir en archivos
#include <fstream>

using namespace std;

FileManagement::FileManagement(string path) : path(path) {}

// Crea y escribe en un archivo
void FileManagement::writeFile(string data){
	ofstream file(path);
	
	if(!file){
		cerr << "Error al abrir el archivo." << endl;
	}
	
	file << data << endl;
	
	file.close();
}

// Lee un archivo y retorna los datos
string FileManagement::readFile(){
	ifstream file(path);
	
	if(!file){
		cerr << "No se pudo abrir el archivo" << endl;
	}
	
	string data, line;
	
	while(getline(file, line)){
		data += line;
	}
	
	file.close();
	return data;
}
