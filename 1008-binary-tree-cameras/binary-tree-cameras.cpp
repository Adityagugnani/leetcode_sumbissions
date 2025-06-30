class Solution {
public:
    int minCameraCover(TreeNode* root) {
        int res = 0;
        helper(root, res, false);

        return res;
    }

    // CASES:
    //      2 = I dont need but dont have a camera
    //      1 = I dont need coz I have a camera
    //      0 = I need and I dont have a camera

    int helper(TreeNode* r, int& res, bool has_parent) {
        if(r) {
            int left = helper(r->left, res, true);
            int right = helper(r->right, res, true);

            //One of my child needs a camera, I'll have to get a camera on me.
            if(!left || !right) {
                res++;
                // I am now in case 1
                return 1;
            }

            //If one of my child has a camera and other doesnot have but doesnot need
            //I can rely on one of my children
            else if(left + right == 3) {

                //I am now in case 2
                return 2;
            }

            //Both my children dont have a camera but they dont need 
            else if(left + right == 4) {

                //Then If I have a parent, I'll leave it for my parent
                //I am now in case 0
                if(has_parent) return 0;

                //If I am Orphan, I'll have to get a camera on me
                ++res;

                //I am now in case 1
                return 1;
            }
        }
        
        //If I am leaf or my both children have the camera,
        //I dont need a camera so I am now in case 2
        return 2;
    }
};