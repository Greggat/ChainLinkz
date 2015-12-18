#pragma once

class ChainLinkz {
private:
	static int chainCount;
	ChainLinkz * fLink; // First Link
	ChainLinkz * nLink; // Next Link
	int chainID;

public:
	int data; // Example Data -- Random Int

	ChainLinkz* next();
	ChainLinkz* last();

	ChainLinkz addLink(ChainLinkz &link);
	ChainLinkz addLink(ChainLinkz *link);
	ChainLinkz operator>>(ChainLinkz &link);
	ChainLinkz operator>>(ChainLinkz *link);

	ChainLinkz ChainLinkz::unlink(ChainLinkz *link);
	ChainLinkz ChainLinkz::unlink(ChainLinkz &link);
	ChainLinkz unlink();

	ChainLinkz* operator[](int i);

	ChainLinkz(int i);
	~ChainLinkz();
};