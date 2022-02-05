int Ship::getRow(int index)
{
    return (posArr[index].at(0) - 48);
}

int Ship::getCol(int index)
{
    return posArr[index].at(1) - 65;
}