#include <stdio.h>
#include "ChainLinkz.h"
#define exists(a) (a?(a->data):(0))

typedef ChainLinkz cl;

int main(int argc, int argv[]) {
	ChainLinkz fChain(1337);
	fChain >> (new ChainLinkz(11)) >> (new  ChainLinkz(22));
	ChainLinkz* chain2 = new ChainLinkz(77);
	fChain.addLink(chain2) >> (new  ChainLinkz(99));

	delete chain2;

	//ChainLinkz chain2(11);
	//ChainLinkz chain3(22);
	//printf("fChain: %x | chain2: %x | chain3: %x\n", &fChain, &chain2, &chain3);
	//fChain.addLink(chain2);
	//fChain.addLink(chain3);
	printf("Data:\n   First Link: %i\n   Third Link: %i\n   Fourth Link: %i\n", exists(fChain[1]), exists(fChain[3]), exists(fChain[4]));
	scanf_s("");
}