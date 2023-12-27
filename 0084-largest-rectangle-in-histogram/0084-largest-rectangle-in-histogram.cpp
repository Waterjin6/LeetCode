class Solution {
public:
	int largestRectangleArea(vector<int>& height) {
		int n = height.size(), area = 0, h, l;

		stack<int> indexes;

		for (int i = 0; i <= n; i++) { // for first to fin
            cout<< "i : "<<i<<endl; 

			while (i == n || (!indexes.empty() && height[indexes.top()] > height[i])) {
				// i is endIdx
				if (i == n && indexes.empty()) {
					h = 0;
				  i++;
				}
				else {
					h = height[indexes.top()]; 
					indexes.pop();
				}			

				l = indexes.empty() ? -1 : indexes.top(); // update length
				area = max(area, h * (i - l - 1)); // update area
                //cout<< "h : "<<h<<", i : "<<i<<", l : "<< l<<", area : "<<area<<endl;
			}

			indexes.push(i);
		}
		return area;
	}
};