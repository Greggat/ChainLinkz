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

	ChainLinkz(int i);
};