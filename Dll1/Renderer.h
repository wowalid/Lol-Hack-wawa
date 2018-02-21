#pragma once

union XMFLOAT4X4 {
	union {
		struct {
			float _11;
			float _12;
			float _13;
			float _14;
			float _21;
			float _22;
			float _23;
			float _24;
			float _31;
			float _32;
			float _33;
			float _34;
			float _41;
			float _42;
			float _43;
			float _44;
		};
		float m[4][4];
	};
};

class Renderer
{
	char _0x0000[32];
	__int32 screenWidth; //0x0020 
	__int32 screenHeight; //0x0024 
	char _0x0028[100];
	XMFLOAT4X4 viewMatrix; //0x008C 
	XMFLOAT4X4 projectionMatrix; //0x00CC 

};


