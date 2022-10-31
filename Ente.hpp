#pragma once

class Ente
{
protected:
    int id;

public:
    Ente(){};
    ~Ente(){};

    virtual void update() = 0;
    virtual void render(){};
};