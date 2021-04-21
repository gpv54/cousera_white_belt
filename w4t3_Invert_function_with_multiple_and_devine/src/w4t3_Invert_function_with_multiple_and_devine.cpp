//============================================================================
// Name        : w4t2_Invert_function.cpp
// Author      : GPV
// Version     : 1
// Copyright   : none
// Description : Invert function with multiple and devine
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Image2 {
  double quality;
  double freshness;
  double rating;
};

struct Params2 {
  double a;
  double b;
  double c;
};

struct Operation
{
	char op;
	double val;
};

class FunctionParts {
public:
	FunctionParts(char ch, double val){
		operation = {ch, val};
	}

	double Apply(double source_value) const {
		if(operation.op == '+'){
			return source_value + operation.val;
		} else if (operation.op == '-'){
			return source_value - operation.val;
		} else if (operation.op == '*'){
			return source_value * operation.val;
		} else if (operation.op == '/'){
			return source_value / operation.val;
		} else {
			cout << "Unknown operations!" << endl;
			return 0.0;
		}
	}

	void Invert(){
		if(operation.op == '+'){
			operation.op = '-';
		} else if (operation.op == '-'){
			operation.op = '+';
		} else if(operation.op == '*'){
			operation.op = '/';
		} else if(operation.op == '/'){
			operation.op = '*';
		} else {
			cout << "Unknown operations!" << endl;
		}
	}
private:
	Operation operation;
};

class Function {
public:
	void AddPart(char ch, double val){
		funcParts.push_back({ch, val});
	}

	double Apply(double val) const {
		for ( const auto &p : funcParts){
			val = p.Apply(val);
		}
		return val;
	}

	void Invert() {
		for ( auto& f : funcParts){
			f.Invert();
		}
		reverse(begin(funcParts), end(funcParts));
	}
private:
	vector<FunctionParts> funcParts;
};

Function MakeWeightFunction(const Params2& params,
                            const Image2& image) {
  Function function;
  function.AddPart('*', params.a);
  function.AddPart('-', image.freshness * params.b);
  function.AddPart('+', image.rating * params.c);
  return function;
}

double ComputeImageWeight(const Params2& params, const Image2& image) {
  Function function = MakeWeightFunction(params, image);
  return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params2& params,
                              const Image2& image,
                              double weight) {
  Function function = MakeWeightFunction(params, image);
  function.Invert();
  return function.Apply(weight);
}

int main() {
  Image2 image = {10, 2, 6};
  Params2 params = {4, 2, 6};
  cout << ComputeImageWeight(params, image) << endl;
  cout << ComputeQualityByWeight(params, image, 52) << endl;
  return 0;
}

