#include <map>
#include <string>

using namespace std;

class WordTree;
class WordNode
{
private:
	friend class WordTree;
	typedef map<string, WordNode> _TreeMap;
	typedef map<string, WordNode>::iterator _TreeMapIterator;

	string m_character;
	_TreeMap m_map;
	WordNode* m_parent;
	
public:
	WordNode(string character);
	WordNode(){
		m_character = "";
	};
	string getCharacter() const{ return m_character; };
	WordNode* findChild(string& nextCharacter);
	WordNode* insertChild(string& nextCharacter);
};





class WordTree
{
public:
	int count;
	WordNode* insert(string &keyword);
	WordNode* insert(const char* keyword);
	WordNode* find(string& keyword);
	WordTree(){ count = 0; };

private:
	WordNode m_emptyRoot;
	int m_pace;
	WordNode* insert(WordNode* parent, string& keyword);
	WordNode* insertBranch(WordNode* parent, string& keyword);
	WordNode* find(WordNode* parent, string& keyword);
};



class WordFilter
{
public:
	static WordFilter* pInstace;
	static WordFilter* sharedInstace();
	static void release();
private:
	WordTree m_tree;

public:
	void load(const char* filepath);
	void censor(string &source);
};
