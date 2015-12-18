#include "ChainLinkz.h"
#include <stdio.h>

int ChainLinkz::chainCount = 0;

ChainLinkz::ChainLinkz(int i) {
	data = i;
	chainID = chainCount++;
	fLink = this;
	nLink = 0;
	printf("Created Link with Value: %i  Addr: %p.\n", data, this);
}

ChainLinkz *ChainLinkz::next() {
	if (nLink)
		return nLink;
	else
		return 0;
}

ChainLinkz *ChainLinkz::last() {
	ChainLinkz * lastLink = fLink;
	while (lastLink->next()) {
		lastLink = lastLink->next();
	}
	return lastLink;
}

ChainLinkz ChainLinkz::addLink(ChainLinkz &link) {
	return addLink(&link);
}

ChainLinkz ChainLinkz::addLink(ChainLinkz *link) {
	if (link->nLink) {
		if (link == link->fLink) { // Replace fLink with new address in all instances of previous chain | Fix the old chain
			ChainLinkz *t_link = link->nLink;
			while (t_link->next()) {
				t_link = t_link->next();
				t_link->fLink = link->nLink;
			}
		}
		else { // Replace nLink for previous link | Fix the old chain
			ChainLinkz *t_link = link->fLink;
			while (t_link != link)
				t_link = t_link->next();
			t_link->nLink = link->next();
		}
	}
	last()->nLink = link;
	link->nLink = 0; //Update values to new chain
	link->fLink = fLink;
	return *link;
}

ChainLinkz ChainLinkz::operator>>(ChainLinkz &link) {
	return addLink(&link);
}
ChainLinkz ChainLinkz::operator>>(ChainLinkz *link) {
	return addLink(link);
}
