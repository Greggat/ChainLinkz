#include <stdio.h>
#include "ChainLinkz.h"

typedef ChainLinkz cl;

int main(int argc, int argv[]) {
	ChainLinkz fChain(1337);
	fChain >> (new ChainLinkz(11)) >> (new  ChainLinkz(22));
	ChainLinkz chain2(77);
	fChain.addLink(chain2);
	//ChainLinkz chain2(11);
	//ChainLinkz chain3(22);
	//printf("fChain: %x | chain2: %x | chain3: %x\n", &fChain, &chain2, &chain3);
	//fChain.addLink(chain2);
	//fChain.addLink(chain3);
	if (fChain.next())
		printf("Data:\n   First Link: %i\n   Next Link: %i\n   Last Link: %u\n",fChain.data,fChain.next()->data,fChain.last()->data);
	scanf_s("");
}