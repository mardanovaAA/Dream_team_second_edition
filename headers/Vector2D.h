#ifndef LIFELIKE_CELLULAR_AUTOMATON_VECTOR2D_H
#define LIFELIKE_CELLULAR_AUTOMATON_VECTOR2D_H

#include <vector>
#include <iostream>
#include "Vector2D.h"

template <typename T>
class Vector2D{
    private:
        std::vector<std::vector<T>> main_vec;
        int width; //horizontal
        int height; //vertical

    public:
        Vector2D(const int &size){
        	for (int i = 0; i < size; i++){
		        main_vec.push_back(std::vector<T> (size, static_cast<T>(0)));
		    }
            width = size;
            height = size;
        };

        Vector2D(){};

        Vector2D(const int &width, const int &height): width(width), height(height){
        	for (int i = 0; i < width; i++){
		        main_vec.push_back(std::vector<T> (height, static_cast<T>(0)));
		    }
        }

        Vector2D(const int &width, const int &height, const T &val): width(width), height(height){
        	for (int i = 0; i < width; i++){
		        main_vec.push_back(std::vector<T> (height, val));
		    }
        }

        int get_width(){
            return width;
        }

        int get_height(){
        	return height;
        }

        /*const std::vector<T>& operator[] (int i) const{
        	return main_vec[i];
        }*/

        std::vector<T>& operator[] (int i) {
            return main_vec[i];
        }

        Vector2D<T>& operator= (const Vector2D<T> &vec){
            this->width = vec.width;
            this->height = vec.height;
            this->main_vec.clear();
            this->main_vec = vec.main_vec;

        	return *this;
        }

        friend std::ostream& operator << (std::ostream& out, const Vector2D<T> &vec){
        	for (int i = 0; i < vec.width; i++){

		        for (int j = 0; j < vec.height; j++){
		            out << vec.main_vec[i][j] << " ";
		        }
		        out << '\n';
	    	}

	    	return out;
        };

        /*template <typename U>
		friend Vector2D<U>& operator >> (std::istream& in, Vector2D<U> &vec){
			for (int i = 0; i < vec.height; i++){
        		for (int j = 0; j < vec.width; j++){
            		in >> vec.main_vec[i][j];
        		}
		    }
		    return vec;
		};   */

};

#endif //LIFELIKE_CELLULAR_AUTOMATON_VECTOR2D_H