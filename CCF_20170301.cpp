//仅设置两个string 输入string和输出string，通过对同一个string进行循环操作，这样可很容易实现嵌套处理
//亮点1：replace和find的结合使用替换字符
//做文本处理的题目不要单纯盯着一行或者一段，可以把所有的输入都当作一次来处理，回车换行符也只不过是一个字符而已
#include <bits/stdc++.h>	
	using namespace std;
	int main()
	{
	string line,text;
	bool x=false;
	getline(cin,line);
	while(true)
	{
		if(line.size()>0)//否则就每次读入一行然后加上被getline忽略掉的\n
		{
			text+=line+"\n";
		}
		else if(line.size()==0&&text.size()>0)//如果line是空行并且text已经有内容了，这个时候准备处理并且输出了，这个开始处理的条件选的很妙！！！！
		{
			//先处理行内
			size_t pos=text.find("_");
			//实现重复查找替换
			while(pos!=string::npos)//这里如果上面不用size_t这里就可以用-1（对于用int 的人）
			{
				text.replace(pos,1,"<em>");//相当于替换策略
				size_t nxp=text.find("_",pos);
				text.replace(nxp,1,"</em>");
				pos=text.find("_",nxp);
			}
			pos=text.find("[");
			//妙呀！！字符串替换，
			while(pos!=string::npos)
			{
				size_t nxp=text.find("]",pos);
				size_t lp=text.find("(",nxp);
				size_t rp=text.find(")",lp);
				string tt=text.substr(pos+1,nxp-pos-1);
				string lk=text.substr(lp+1,rp-lp-1);
				text.replace(text.begin()+pos,text.begin()+rp+1,"<a href=\""+lk+"\">"+tt+"</a>");
				pos=text.find("[",rp);
			}
			
			//再处理段
			if(text[0]=='#')
			{
				int i=0;
				while(text[i]=='#') ++i;
				text=text.substr(i+1);
				text="<h"+string(1,'0'+i)+">"+text;
				text.insert(text.size()-1,"</h"+string(1,'0'+i)+">");//插在换行符之前
			}
			else if(text[0]=='*')
			{
				text.insert(0,"<ul>\n");//换行符也可以插入
				text.insert(text.size(),"</ul>\n");
				size_t pos=text.find("*");
				while(pos!=string::npos)
				{
					size_t nxp=text.find("\n",pos);
					text.insert(nxp,"</li>");
					text.replace(pos,2,"<li>");
					pos=text.find("*",nxp);
				}
			}
			else
			{
				text="<p>"+text;
				text.insert(text.size()-1,"</p>");
			}
			cout<<text;
			text="";
		}
		line="";
		if(x) break;
		if(!getline(cin,line))//如果读到了文件的末尾
		{
			x=true;
			line="";
		}
	}
		return 0;
	}

