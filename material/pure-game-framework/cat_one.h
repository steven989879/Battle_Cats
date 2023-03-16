#include <list>
#include <vector>
#include <map>
#include"windef.h"
#include"wingdi.h"
#include"atltypes.h"
#include"time.h"
#include"afxwin.h"
#include".\Source\.\Library\gameutil.h"
#include"monster.h"


using namespace std;

namespace game_framework {

	/////////////////////////////////////////////////////////////////////////////
	// �o��class���ѰʺA(�i�H����)���ϧ�
	// �C��Public Interface���Ϊk���n���AImplementation�i�H����
	/////////////////////////////////////////////////////////////////////////////

	class cat_one : public monster {
	public:
		cat_one();

	protected:
		int price = 50 ;
		int heart = 30;
		int attack_range = 5;
		int power = 5 ;
		int walk_speed = 2 ;
		int cool_time = 5;
	};

}
