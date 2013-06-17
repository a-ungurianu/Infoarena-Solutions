#include <iostream>
#include <fstream>
using namespace std;
ifstream in ("maxsecv.in"); ofstream out ("maxsecv.out");

int main()
{
	int n;
	in >> n;
	bool in1Seq = false;
	int curSeqLen = 0;
	int max=0,lastMax=0;
	while(n--)
	{
		char t;
		in >> t;
		if(t=='1')
		{
			if(in1Seq)
				curSeqLen++;
			else
			{
				in1Seq=true;
				//cerr << "SEQST\n";
				curSeqLen=1;
			}
		}
		else
		{
			if(in1Seq)
			{
				if(curSeqLen>=max)
				{
					lastMax = max;
					max = curSeqLen;
				}
				else if(curSeqLen>lastMax)lastMax = curSeqLen;
				//cerr << "SEQFN\n";
				in1Seq=false;
			}
		}
	}
	if(in1Seq)
			{
				if(curSeqLen>=max)
				{
					lastMax = max;
					max = curSeqLen;
				}
				//cerr << "SEQFN\n";
				in1Seq=false;
			}
	out << max + lastMax;
}
