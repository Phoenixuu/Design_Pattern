//Abtract class: pure function area
class Shape{
public:
	virtual double area() const = 0;
};
class Circle : public Shape{
};

class Shape{
private:
	virtual double area() const = 0;
};
class Circle : private Shape{
};

class Shape{
protected:
	virtual double area() const = 0;
};
class Circle : protected Shape{
};

class FriendShape{
	friend class Circle;
private:
	double privateValue;
public:
	double getPrivateValue() const {
		return privateValue;
	}
};

class Circle : public FriendShape{
public:
	double getFriendShapePrivateValue() const{
		return privateValue;
	}
};

