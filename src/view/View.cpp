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

#include "View.h"
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void View::colorTerm(string data, string color){
	
	unordered_map<string, string> colors = {
		{"black", "\033[30m"},
		{"red", "\033[31m"}, 
		{"green", "\033[32m"}, 
		{"yellow", "\033[33m"}, 
		{"blue", "\033[34m"}, 
		{"magenta", "\033[35m"}, 
		{"cyan", "\033[36m"}, 
		{"white", "\033[37m"}, 
		{"reset", "\033[0m"}, 
	};

	cout << colors[color] << data << "\033[0m" << endl;
}

void View::colorTerm(string data){
	cout << "\033[0m" << data << "\033[0m" << endl;
}






