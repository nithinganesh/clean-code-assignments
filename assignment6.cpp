#include <string>
#include <vector>

class DocumentPart
{
  private:
  std::wstring Text;

  public:
  std::wstring getText() const
  {
    return Text;
  }
  void setText(const std::wstring &value)
  {
    Text = value;
  }
  virtual std::wstring ToHTML() = 0;
  virtual std::wstring ToPlainText() = 0;
  virtual std::wstring ToLatex() = 0;
};

class PlainText : public DocumentPart
{
  public:
  std::wstring ToHTML() override
  {
    return this->getText();
  }
  std::wstring ToPlainText() override
  {
    return this->getText();
  }
  std::wstring ToLatex() override
  {
    return this->getText();
  }
};

class BoldText : public DocumentPart
{
  public:
  std::wstring ToHTML() override
  {
    return L"<b>" + this->getText() + L"</b>";
  }
  std::wstring ToPlainText() override
  {
    return L"**" + this->getText() + L"**";
  }
  std::wstring ToLatex() override
  {
    return L"\\textbf{" + this->getText() + L"}";
  }
};

class Hyperlink : public DocumentPart
{
  private:
  std::wstring Url;

  public:
  std::wstring getUrl() const
  {
    return Url;
  }

  void setUrl(const std::wstring &value)
  {
    Url = value;
  }

  std::wstring ToHTML() override
  {
    return L"<a href=\"" + this->getUrl() + L"\">" + this->getText() + L"</a>";
  }
  std::wstring ToPlainText() override
  {
    return this->getText() + L" [" + this->getUrl() + L"]";
  }
  std::wstring ToLatex() override
  {
    return L"\\href{" + this->getUrl() + L"}{" + this->getText() + L"}";
  }
};

class Document
{
  public:
  std::vector<DocumentPart*> m_parts;
  
  virtual std::wstring ToHTML()=0;
  virtual std::wstring ToPlainText()=0;
  virtual std::wstring ToLatex()=0;
};

class Document_1 : public Document
{

  public:
  std::wstring ToHTML() override
  {
    std::wstring output = L"";
    for (auto part : m_parts)
    {
      output += part->ToHTML();
    }
    return output;
  }

  std::wstring ToPlainText() override
  {
    std::wstring output = L"";
    for (auto part : m_parts)
    {
      output += part->ToPlainText();
    }
    return output;
  }

  std::wstring ToLatex() override
  {
    std::wstring output = L"";
    for (auto part : m_parts)
    {
      output += part->ToLatex();
    }
    return output;
  }
};
