#include<iostream>
#include<fstream>
#include<String.h>
using namespace std;
class dictionary
{
public :
    char word[50];
private:
    char meaning[100];
public:
    void accept()
    {
        cout<<endl<<"Enter word";
        cin>>word;
        cout<<endl<<"Enter meaning";
        cin>>meaning;
    }
    void display()
    {
        cout<<endl<<word<<"\t\t"<<meaning;
    }
};
dictionary obj;
void addword()
{
    obj.accept();
    fstream wr;
    wr.open("mywords.txt",ios::app);
    wr.write((char*)&obj,sizeof(obj));
    cout<<endl<<"object written";
    wr.close();
}
void readwords()
    {
        fstream rd;
        rd.open("mywords.txt",ios::in);
        rd.seekg(0,ios::end);
        int n=rd.tellg();
        int nwords=n/sizeof(obj);
        rd.seekg(0,ios::beg);
        for(int i=1;i<=nwords;i++)
        {
          rd.read((char*)&obj,sizeof(obj));
          obj.display();
        }
    }
    void searchword()
    {
        char sr[50];
        cout<<endl<<"Enter word to be searched";
        cin>>sr;
        fstream rd;
        rd.open("mywords.txt",ios::in);
        rd.seekg(0,ios::end);
        int n=rd.tellg();
        int nwords=n/sizeof(obj);
        rd.seekg(0,ios::beg);
        for(int i=1;i<=nwords;i++)
        {
            rd.read((char*)&obj,sizeof(obj));
            if (strcmp(sr,obj.word)==0)
            {
                obj.display();
            }

        }
    }
    void removeword()
    {
        fstream rd,wr;
        rd.open("mywords.txt",ios::in);
        wr.open("temp.txt",ios::out);
        char s[50];
        cout<<endl<<"Enter word to be removed";
        cin>>s;
        rd.seekg(0,ios::end);
        int n=rd.tellg();
        int nwords=n/sizeof(obj);
        rd.seekg(0,ios::beg);
        for(int i=1;i<=nwords;i++)
        {
            rd.read((char*)&obj,sizeof(obj));
            if (strcmp(s,obj.word)==0)
            {
                cout<<endl<<"Word deleted successfully";
            }
            else
            {
                wr.write((char*)&obj,sizeof(obj));
            }
        }
        rd.close();
        wr.close();
        remove("mywords.txt");
        rename("temp.txt","mywords.txt");
        }
        void updateword()
        {
        fstream rd,wr;
        rd.open("mywords.txt",ios::in);
        wr.open("temp.txt",ios::out);
        char s[50];
        cout<<endl<<"Enter word to be updated";
        cin>>s;
        rd.seekg(0,ios::end);
        int n=rd.tellg();
        int nwords=n/sizeof(obj);
        rd.seekg(0,ios::beg);
        for(int i=1;i<=nwords;i++)
        {
            rd.read((char*)&obj,sizeof(obj));
            if (strcmp(s,obj.word)==0)
            {
                obj.accept();
            }
            wr.write((char*)&obj,sizeof(obj));

        }
        rd.close();
        wr.close();
        remove("mywords.txt");
        rename("temp.txt","mywords.txt");


        }
main()
{
  cout<<endl<<"************************************************************************"<<"\n"<<"\t\t"<<"Welcome to My Dictionary";
  cout<<endl<<"***********************************************************************";
  int e=0,choice;
  while(e!=1)
  {
      cout<<endl<<"Enter 1 to add word";
      cout<<endl<<"Enter 2 to search word";
      cout<<endl<<"Enter 3 to view all words";
      cout<<endl<<"Enter 4 to delete word";
      cout<<endl<<"Enter 5 to update word";
      cout<<endl<<"Enter 6 to exit";
      cout<<endl<<"Enter choice";
      cin>>choice;
      switch (choice)
      {
      case 1:
        {
            addword();
            break;
        }
      case 2:
        {
            searchword();
            break;
        }
      case 3:
        {
            readwords();
            break;
        }
      case 4:
        {
            removeword();
            break;
        }
      case 5:
        {
            updateword();
            break;

        }
      case 6:
        {

            e=1;
            break;
        }
      }
  }

}

