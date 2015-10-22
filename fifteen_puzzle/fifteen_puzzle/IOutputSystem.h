#pragma once

class IOutputSystem
{
public:
	virtual void run() = 0;
    virtual ~IOutputSystem(){};
};