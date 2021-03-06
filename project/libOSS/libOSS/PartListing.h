/*
 Copyright 2012 baocai zhang. All rights reserved.
 
 Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 
 Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 THIS SOFTWARE IS PROVIDED BY THE FREEBSD PROJECT ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE FREEBSD PROJECT OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 The views and conclusions contained in the software and documentation are those of the authors and should not be interpreted as representing official policies, either expressed or implied, of the FreeBSD Project.
 */

/*
 @author baocai zhang
 website:www.giser.net
 email:zhangbaocaicug@gmail.com
 */
#pragma warning(disable:4251)
#ifdef LIBOSS_EXPORTS
#define OSSDLL_API __declspec(dllexport)
#define EXPIMP_TEMPLATE
#else
#define OSSDLL_API __declspec(dllimport)
#define EXPIMP_TEMPLATE extern
#endif 
#pragma once
#include<string>
#include<vector>
#include"Owner.h"
#include"PartSummary.h"
using namespace std;
namespace OSS
{
/**
@class PartListing
@brief 多点上传中，罗列Part结果对象
*/
class OSSDLL_API PartListing
{
public:
	PartListing(void);
	PartListing(string & strXML);
	~PartListing(void);
public:
	string bucketName;
    string key;
    string uploadId;
    int maxParts;
    int partNumberMarker;
    Owner owner;
    Owner initiator;
    string storageClass;
    bool isTruncated;
    int nextPartNumberMarker;
    vector<PartSummary> parts;
public:
	void MakePartListing(string & strXML);
};
}

