struct Line{ 
    Pt st, ed;
    Line(){}
    Line(Pt _st, Pt _ed){
        st=_st, ed=_ed;
    }
};

struct Circle{ 
    Pt o; // 圓心
    int r; // 半徑
};

struct poly{
    int n; // n 邊形
    vector<Pt> pts; 
};

struct Pt{
    int x,y;
    Pt(){}
    Pt(int _x, int _y){
        x=_x, y=_y;
    }

    Pt operator-(const Pt a){
        return Pt(x-a.x, y-a.y);
    }

    bool operator<(const Pt a){
        return x<a.x || ((x==a.x) && (y<a.y));
    }

    bool operator==(const Pt a){
        return x==a.x && y==a.y;
    }

    bool operator!=(const Pt a){
        return x!=a.x || y!=a.y;
    }

    bool collinearity(Pt a, Pt b, Pt c){//面積為零則共線
        return area(a, b, c)==0;
    }

    bool intersection(Line a, Line b){ //兩線段是否交會於一點
        return inLine(a.st, b) || inLine(a.ed, b) || inLine(b.st, a) || inLine(b.ed, a) 
                || (cross(a.st, a.ed, b.st)*cross(a.st, a.ed, b.ed)<0 && cross(b.st, b.ed, a.st)*cross(b.st, b.ed, a.ed)<0); 
    }

    bool inLine(Pt p, Line li){
        return collinearity(li.st, li.ed, p) && dot((li.st-p), (li.ed-p)) < 0;
    }

    friend int cross(Pt o, Pt a ,Pt b){//外積，小於 0 是逆時針
        Pt lhs=o-a, rhs=o-b;
        return lhs.x*rhs.y - lhs.y*rhs.x;
    }

    friend int area(Pt a,Pt b,Pt c){
        return abs(cross(a, b, c));
    }

    friend  int dot(const Pt a, const Pt b){ //程式碼中內積通常用*表示
        return b.x*a.x + b.y*a.y;
    }
};