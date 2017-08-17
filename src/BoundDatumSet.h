#pragma once

#include <vector>
#include <BoundDatum.h>

namespace mssql
{
	class ResultSet;

	class BoundDatumSet
	{
	public:	
		BoundDatumSet();
		bool reserve(shared_ptr<ResultSet> set) const;
		bool bind(Handle<Array> &node_params);
		Local<Array> unbind();	
		void clear() { bindings->clear(); }
		size_t size() { return bindings->size(); }
		BoundDatum & atIndex(int i) { return (*bindings)[i]; }
		vector<BoundDatum>::iterator begin() { return bindings->begin(); }
		vector<BoundDatum>::iterator end() { return bindings->end(); }

		char * err;
		int first_error;

	private:
		typedef vector<BoundDatum> param_bindings; 
		int output_param_count;
		shared_ptr<param_bindings> bindings;
	};
}
