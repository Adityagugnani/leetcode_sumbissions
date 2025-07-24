/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    vector<int>v;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    for(auto u:nums){
            v.push_back(u);
        }
        reverse(v.begin(),v.end());
	}
	int peek() {
        return v[v.size()-1];
	}
	int next() {
	    int val=v[v.size()-1];
        v.pop_back();
        return val;
	}
	
	bool hasNext() const {
	    if(v.empty()){
            return false;
        }
        else{
            return true;
        }
	}
};