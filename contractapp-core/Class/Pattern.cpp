#include "Pattern.h"

Pattern::Pattern(int vector_size) :
    mParagraphs(vector_size),
    mTitles(vector_size)
{

}

void Pattern::setName(const QString &name)
{
    mName = name;
}

void Pattern::setId(int id)
{
    mId = id;
}

QString Pattern::getName() const
{
    return mName;
}

int Pattern::getId() const
{
    return mId;
}

void Pattern::removeTitle()
{
    mTitles.pop_back();
}

void Pattern::addTitle(const QString& value)
{
    mTitles.push_back(value);
}

void Pattern::removeParagraph()
{
    mParagraphs.pop_back();
}

void Pattern::addParagraph(const QString& value)
{
    mParagraphs.push_back(value);
}

void Pattern::setParagraph(int index, const QString &value)
{
    mParagraphs[index] = value;
}

int Pattern::getTitlesSize() const
{
    return static_cast<int>(mTitles.size());
}

int Pattern::getParagraphsSize() const
{
    return static_cast<int>(mParagraphs.size());
}

QString Pattern::getParagraph(int index) const
{
    return mParagraphs.at(index);
}

QString Pattern::getTitle(int index) const
{
    return mTitles.at(index);
}

void Pattern::clear()
{
    mName = "";
    mId = -1;
    mTitles.clear();
    mParagraphs.clear();
}
