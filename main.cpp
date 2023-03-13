#include<bits/stdc++.h>
using namespace std;
fstream File_name;
class student{
    public:
	string name;
	string dob;
	float t_percen;
	float i_percen;
	int id;
	string address;
	string f_details[3];
	string m_details[3];
	int f_income;
	int m_income;
	int srmrank;
	string branch[4];
	int fee_paid;
	int scholarship;
	int due;
	int height;
	int bf;
	string comments;
	student* left;
	student* right;
};
student* root;
//student* srm;
student* create(){
	int c;
	student* temp=new student();
	//fstream File_name;
	cout<<"Enter the name of student"<<endl;
	getline(cin>>ws,temp->name);
	cout<<"Enter the date of birth"<<endl;
	getline(cin,temp->dob);
    cout<<"Enter the SSC or CBSE or ICSE percentage"<<endl;
    cout<<"Choose the 1.grade\t  2.pecentage system\n Enter your choice"<<endl;
    cin>>c;
    if(c==1){
    	float k;
    	cout<<"enter the grade"<<endl;
    	cin>>k;
    	k=k*100;
    	temp->t_percen=k;
	}
	else{
		float k;
    	cout<<"enter the percentage"<<endl;
    	cin>>k;
    	temp->t_percen=k;
    }
    cout<<"Enter the Intermediate or CBSE 12th or ICSE 12th percentage\n"<<endl;
    cout<<"Choose the 1.grade, 2.pecentage system\n Enter your choice\n"<<endl;
    cin>>c;
    if(c==1){
    	float k;
    	cout<<"Enter the grade"<<endl;
    	cin>>k;
    	k=k*100;
    	temp->i_percen=k;
	}
	else{
		float k;
    	cout<<"Enter the percentage"<<endl;
    	cin>>k;
    	temp->i_percen=k;
    }
    cout<<"Enter your address"<<endl;
    getline(cin>>ws,temp->address);
    cout<<"Enter your father name"<<endl;
    getline(cin,temp->f_details[0]);
    cout<<"Enter your father's occupation"<<endl;
    getline(cin,temp->f_details[1]);
    cout<<"Enter the income of your father in rupees"<<endl;
    cin>>temp->f_income;
    cout<<"Enter your mother name"<<endl;
    getline(cin>>ws,temp->m_details[0]);
    cout<<"Enter your mother's occupation"<<endl;
    getline(cin,temp->m_details[1]);
    cout<<"Enter the income of your mother in rupees ,if your mother is homemaker enter zero"<<endl;
    cin>>temp->m_income;
    cout<<"Enter your SRMJEEE rank"<<endl;
    cin>>temp->srmrank;
    cout<<"Enter the course you want to pursue"<<endl;
    getline(cin>>ws,temp->branch[0]);
    cout<<"Enter the branch of your course"<<endl;
    getline(cin,temp->branch[1]);
    cout<<"Enter the specialization you want to pursue"<<endl;
    getline(cin>>ws,temp->branch[2]);
    cout<<"Details successfully entered"<<endl;
    temp->left=NULL;
	temp->right=NULL;
    File_name.open("srm.txt",ios::app);
    if(File_name.is_open()){
    	File_name<<"Name : "<< temp->name<<","<<"\n";
    	File_name<<"D.O.B. : "<< temp->dob<<","<<"\n";
    	File_name<<"Tenth percentage:"<<temp->t_percen<<","<<"\n";
    	File_name<<"Inter percentage: "<< temp->i_percen<<","<<"\n";
    	File_name<<"Address :"<<temp->address<<","<<"\n";
    	File_name<<"Father name :"<<temp->f_details[0]<<","<<"\n";
    	File_name<<"Occupation : "<< temp->f_details[1]<<","<<"\n";
    	File_name<<"Income : "<< temp->f_income<<","<<"\n";
    	File_name<<"SRMJEEE rank :"<<temp->srmrank<<","<<"\n";
    	File_name << "\n";
    	File_name << "\n";
    	File_name << "\n";
    	File_name.close();
	}
	return temp;
}
int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}
int height(student* root){
	if(root==NULL){
		return -1;
	}
	return 1+max(height(root->left),height(root->right));
}
int bfc(student* root){
	return (height(root->left) - height(root->right));
}
student* search(student* root, int val){
	if(root==NULL){
		cout<<"Student not found"<<endl;
		return NULL;
	}
	if(root->id==val){
		cout<<"Student found "<<endl;
		cout<<"Fees brochure for respective courses"<<endl;
		cout<<"1. B.Sc.   Rs.4.65L\n2. B.E./B.Tech  Rs.2.8L\n3. B.A. Rs.4.65L\n4. BBA  Rs.7.65L\n5. B.Com  Rs.4.65L\n6.Exit"<<endl;
		cout<<"You prefered course is "<<root->branch[0]<<endl;
		int f;
		cin>>f;
		switch(f){
			case 1: root->fee_paid=465000-(root->scholarship);
			        break;
			case 2: root->fee_paid=280000-(root->scholarship);
			        break;
			case 3: root->fee_paid=465000-(root->scholarship);
			        break;
			case 4: root->fee_paid=765000-(root->scholarship);
			        break;
			case 5: root->fee_paid=465000-(root->scholarship);
				    break;
			case 6: exit(0);
			        break;

		}

	return root;
	}
    if(root->id<val){
	    root->right=search(root->right,val);
    }
    else{
	    root->left=search(root->left,val);
    }
	return root;

}
int getBalance(student *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}
student* inox(student* root){
	if(!root){
		return NULL;
	}
	inox(root->left);
	root->height=height(root);
    inox(root->right);
    return root;
}
student* inoh(student* root){
	if(!root){
		return NULL;
	}
	inoh(root->left);
	root->bf=bfc(root);
    inoh(root->right);
    return root;
}
student* leftrotate(student* root){
	student* rightsubtree=root->right;
	student* rightsubtreeleft=rightsubtree->left;
    rightsubtree->left=root;
    root->right=rightsubtreeleft;
    root->height=max(height(root->left),height(root->right))+1;
	rightsubtree->height=max(height(rightsubtree->left),height(rightsubtree->right))+1;
    return rightsubtree;



}
student* rightrotate(student* root){
	if(!root){
		return NULL;
	}
	student* leftsubtree=root->left;
	student* leftsubtreeright=leftsubtree->right;
	leftsubtree->right=root;
	root->left=leftsubtreeright;
	root->height=max(height(root->left),height(root->right))+1;
	leftsubtree->height=max(height(leftsubtree->left),height(leftsubtree->right))+1;
	return leftsubtree;
}
student* leftrightrotate(student* root){
	root->left=leftrotate(root->left);
	return rightrotate(root);

}
student* rightleftrotate(student* root){
	root->right=rightrotate(root->right);
	return leftrotate(root);

}
int min(student* root){
	if(!root->left)
        return root->srmrank;
    return min(root->left);
}
student* preod(student* root){
	if(root==NULL){
		return NULL;
	}
	root->left=preod(root->left);
	if(root->due!=0){
		cout<<root->name<<" "<<root->fee_paid<<" "<<root->id<<root->scholarship<<endl;
	}
	root->right=preod(root->right);
	return root;
}
int mind(student* root){
	if(!root->left)
        return root->id;
    return mind(root->left);
}
student* del(student* root,int val){
	if(root==NULL){
	    return NULL;
	}
	if(root->id<val){
		root->right=del(root->right,val);
	}
	else if(root->id>val){
		root->left=del(root->left,val);
	}
	else{
		if(!root->left && !root->right){
			return NULL;
		}
		if(!root->left){
			student* temp=root->right;
			delete root;
			return temp;

		}
		else if(!root->right){
			student* temp=root->left;
			delete root;
			return temp;

		}
		else{
			int minv=mind(root->right);
			root->id=minv;
			root->right=del(root->right,minv);
		}
	}
	if(root==NULL){
		return root;
	}
    root->height = 1 + max(height(root->left),height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightrotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftrotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }
    return root;

}
student* print(student* root){
	if(!root){
		return NULL;
	}
	cout<<"Name : "<<root->name<<" \n"<<"ID : "<<root->id<<" \n"<<"D.O.B. "<<root->dob<<" \n"<<"SRMJEEE rank : "<<root->srmrank<<"\n"<<"Scholarship : "<<root->scholarship<<"\n"<<"Branch : "<<root->branch[0]<<"\n"<<"Branch : "<<root->branch[1]<<"\n";
	cout<<root->comments<<endl;
	cout<<endl<<endl<<endl;
	print(root->left);
	print(root->right);
	return root;
}
student* inorder(student* root){
	if(!root){
		return NULL;
	}
	root->left=inorder(root->left);
	static int k=100;
	cout<<root->name<<endl;
	cout<<root->branch[0]<<endl;
	cout<<root->fee_paid<<endl;
	cout<<root->srmrank<<endl;
	if(root->srmrank<100){
		root->scholarship=100000;
	}
	else if(root->srmrank<500){
		root->scholarship=50000;
	}
	else if(root->srmrank<2000){
		root->scholarship=10000;
	}
	else{
		root->scholarship=0;
	}
	cout<<"He got scholarship of "<<root->scholarship<<endl;
	root->id =k;
	k=k+1;
	cout<<"Enter comments"<<endl;
	getline(cin>>ws,root->comments);
    root->right=inorder(root->right);
    return root;
}
student* insert(student* root,student* temp){
	if(root==NULL){
		return temp;
	}
	if(root->srmrank < temp->srmrank){
		root->right= insert(root->right,temp);
	}
	else if(root->srmrank>temp->srmrank){
		root->left= insert(root->left,temp);
	}
	else{
		return root;
	}
	root->height = 1 + max(height(root->left),height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && temp->srmrank < root->left->srmrank)
        return rightrotate(root);

    if (balance < -1 && temp->srmrank > root->right->srmrank)
        return leftrotate(root);

    if (balance > 1 && temp->srmrank > root->left->srmrank) {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    if (balance < -1 && temp->srmrank < root->right->srmrank) {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}
int main(){
	int c;
	cout<<"************WELCOME TO SRM UNIVERSITY AP************"<<endl;
	cout<<"SRM University-AP, Andhra Pradesh is a multi-stream research university with a focus on diverse fields."<<endl;
	cout<<"From Engineering to Sciences and Liberal Arts to Management, SRM University-AP's vision is to emerge"<<endl;
	cout<<"as a world-class university that is globally connected, nationally relevant, and regionally transformative. It"<<endl;
	cout<<"has an ambitious plan to be in the top world-class universities in ten years."<<endl;
	cout<<"****************Our acheivements************"<<endl;
	cout<<"* Faculty with international exposure  100%"<<endl;
	cout<<"* Student faculty ratio 10:1"<<endl;
	cout<<"* 150 acres campus designed by world renowned architects"<<endl;
	cout<<"* 60+  Collaborations with the world’s best universities"<<endl;
	cout<<"* Courses offering \n";
	cout<<"1. B.Sc(3 years)\n 2. B.E./B.Tech(4 years)\n 3. B.A.(3 years)\n 4. BBA(3 years)\n 5.B.com (3 years)"<<endl;
	cout<<endl<<endl<<endl;
	while(1){
		cout<<"Choose the option"<<endl;
		cout<<"1. Enter you want to add new student "<<endl;
		cout<<"2. To verifing student details and putting comments"<<endl;
		cout<<"3. To verifying fee information and giving scholarship and paying the fees"<<endl;
		cout<<"4. Printing all student information"<<endl;
		cout<<"5. To remove the student from college"<<endl;
		//cout<<"6. Printing students who have dues"<<endl;
		cout<<"7. Exit"<<endl;
		cin>>c;
	    switch(c){
	  	    case 1: root=insert(root,create());
	  	            root=inox(root);
                    root=inoh(root);
	  	            break;
	  	    case 2: root =inorder(root);
	  	            break;
	    	case 3: int c;
			        cout<<"Enter the id to search the student "<<endl;
	    	        cin>>c;
			        root=search(root,c);
			        break;
			case 4: int x;
			        cout<<"Click 1 for new entered data and 2 for printing all data"<<endl;
			        cin>>x;
			        if(x==1){
			        root=print(root);
			        }
			        else{
			        File_name.open("srm.txt",ios::in); //ect
                    if(File_name.is_open()){   //checking whether the file is open
                        string tp;
                        while(getline(File_name, tp)){  //read data from file object and put it into string.
                             cout << tp << " ";
                        }
                        File_name.close();   //close the file object.
                    }
                    cout<<endl<<endl<<endl;
                    }
                    break;
			case 5: int idno;
			        cout<<"Enter the id number you want to remove the student"<<endl;
			        cin>>idno;
			        root=del(root,idno);
			        root=inox(root);
                    root=inoh(root);
			        break;
			//case 6: root=preod(root);
			        //break;
			case 7:
				    exit(0);

	  	}
    }
    return 0;
}
