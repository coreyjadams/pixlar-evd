// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME Pixlar_CoreDict

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// Since CINT ignores the std namespace, we need to do so in this file.
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "GeoService.h"
#include "sparse_vector.h"
#include "RawBase.h"
#include "Point.h"
#include "Utils.h"
#include "ReadDQMFile.h"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *evdcLcLGeoService_Dictionary();
   static void evdcLcLGeoService_TClassManip(TClass*);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::evd::GeoService*)
   {
      ::evd::GeoService *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::evd::GeoService));
      static ::ROOT::TGenericClassInfo 
         instance("evd::GeoService", "GeoService.h", 27,
                  typeid(::evd::GeoService), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &evdcLcLGeoService_Dictionary, isa_proxy, 4,
                  sizeof(::evd::GeoService) );
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::evd::GeoService*)
   {
      return GenerateInitInstanceLocal((::evd::GeoService*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::evd::GeoService*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *evdcLcLGeoService_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::evd::GeoService*)0x0)->GetClass();
      evdcLcLGeoService_TClassManip(theClass);
   return theClass;
   }

   static void evdcLcLGeoService_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *evdcLcLRawBase_Dictionary();
   static void evdcLcLRawBase_TClassManip(TClass*);
   static void *new_evdcLcLRawBase(void *p = 0);
   static void *newArray_evdcLcLRawBase(Long_t size, void *p);
   static void delete_evdcLcLRawBase(void *p);
   static void deleteArray_evdcLcLRawBase(void *p);
   static void destruct_evdcLcLRawBase(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::evd::RawBase*)
   {
      ::evd::RawBase *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::evd::RawBase));
      static ::ROOT::TGenericClassInfo 
         instance("evd::RawBase", "RawBase.h", 40,
                  typeid(::evd::RawBase), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &evdcLcLRawBase_Dictionary, isa_proxy, 4,
                  sizeof(::evd::RawBase) );
      instance.SetNew(&new_evdcLcLRawBase);
      instance.SetNewArray(&newArray_evdcLcLRawBase);
      instance.SetDelete(&delete_evdcLcLRawBase);
      instance.SetDeleteArray(&deleteArray_evdcLcLRawBase);
      instance.SetDestructor(&destruct_evdcLcLRawBase);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::evd::RawBase*)
   {
      return GenerateInitInstanceLocal((::evd::RawBase*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::evd::RawBase*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *evdcLcLRawBase_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::evd::RawBase*)0x0)->GetClass();
      evdcLcLRawBase_TClassManip(theClass);
   return theClass;
   }

   static void evdcLcLRawBase_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   static TClass *evdcLcLReadDQMFile_Dictionary();
   static void evdcLcLReadDQMFile_TClassManip(TClass*);
   static void *new_evdcLcLReadDQMFile(void *p = 0);
   static void *newArray_evdcLcLReadDQMFile(Long_t size, void *p);
   static void delete_evdcLcLReadDQMFile(void *p);
   static void deleteArray_evdcLcLReadDQMFile(void *p);
   static void destruct_evdcLcLReadDQMFile(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::evd::ReadDQMFile*)
   {
      ::evd::ReadDQMFile *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::evd::ReadDQMFile));
      static ::ROOT::TGenericClassInfo 
         instance("evd::ReadDQMFile", "ReadDQMFile.h", 42,
                  typeid(::evd::ReadDQMFile), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &evdcLcLReadDQMFile_Dictionary, isa_proxy, 4,
                  sizeof(::evd::ReadDQMFile) );
      instance.SetNew(&new_evdcLcLReadDQMFile);
      instance.SetNewArray(&newArray_evdcLcLReadDQMFile);
      instance.SetDelete(&delete_evdcLcLReadDQMFile);
      instance.SetDeleteArray(&deleteArray_evdcLcLReadDQMFile);
      instance.SetDestructor(&destruct_evdcLcLReadDQMFile);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::evd::ReadDQMFile*)
   {
      return GenerateInitInstanceLocal((::evd::ReadDQMFile*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const ::evd::ReadDQMFile*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *evdcLcLReadDQMFile_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::evd::ReadDQMFile*)0x0)->GetClass();
      evdcLcLReadDQMFile_TClassManip(theClass);
   return theClass;
   }

   static void evdcLcLReadDQMFile_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
} // end of namespace ROOT for class ::evd::GeoService

namespace ROOT {
   // Wrappers around operator new
   static void *new_evdcLcLRawBase(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::evd::RawBase : new ::evd::RawBase;
   }
   static void *newArray_evdcLcLRawBase(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::evd::RawBase[nElements] : new ::evd::RawBase[nElements];
   }
   // Wrapper around operator delete
   static void delete_evdcLcLRawBase(void *p) {
      delete ((::evd::RawBase*)p);
   }
   static void deleteArray_evdcLcLRawBase(void *p) {
      delete [] ((::evd::RawBase*)p);
   }
   static void destruct_evdcLcLRawBase(void *p) {
      typedef ::evd::RawBase current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::evd::RawBase

namespace ROOT {
   // Wrappers around operator new
   static void *new_evdcLcLReadDQMFile(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::evd::ReadDQMFile : new ::evd::ReadDQMFile;
   }
   static void *newArray_evdcLcLReadDQMFile(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) ::evd::ReadDQMFile[nElements] : new ::evd::ReadDQMFile[nElements];
   }
   // Wrapper around operator delete
   static void delete_evdcLcLReadDQMFile(void *p) {
      delete ((::evd::ReadDQMFile*)p);
   }
   static void deleteArray_evdcLcLReadDQMFile(void *p) {
      delete [] ((::evd::ReadDQMFile*)p);
   }
   static void destruct_evdcLcLReadDQMFile(void *p) {
      typedef ::evd::ReadDQMFile current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::evd::ReadDQMFile

namespace ROOT {
   static TClass *vectorlEvectorlEintgRsPgR_Dictionary();
   static void vectorlEvectorlEintgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEintgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEintgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEintgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEintgRsPgR(void *p);
   static void destruct_vectorlEvectorlEintgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<int> >*)
   {
      vector<vector<int> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<int> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<int> >", -2, "vector", 214,
                  typeid(vector<vector<int> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEintgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<vector<int> >) );
      instance.SetNew(&new_vectorlEvectorlEintgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEintgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEintgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEintgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEintgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<int> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<vector<int> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEintgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<int> >*)0x0)->GetClass();
      vectorlEvectorlEintgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEintgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEintgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<int> > : new vector<vector<int> >;
   }
   static void *newArray_vectorlEvectorlEintgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<int> >[nElements] : new vector<vector<int> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEintgRsPgR(void *p) {
      delete ((vector<vector<int> >*)p);
   }
   static void deleteArray_vectorlEvectorlEintgRsPgR(void *p) {
      delete [] ((vector<vector<int> >*)p);
   }
   static void destruct_vectorlEvectorlEintgRsPgR(void *p) {
      typedef vector<vector<int> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<int> >

namespace ROOT {
   static TClass *vectorlEvectorlEfloatgRsPgR_Dictionary();
   static void vectorlEvectorlEfloatgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEvectorlEfloatgRsPgR(void *p = 0);
   static void *newArray_vectorlEvectorlEfloatgRsPgR(Long_t size, void *p);
   static void delete_vectorlEvectorlEfloatgRsPgR(void *p);
   static void deleteArray_vectorlEvectorlEfloatgRsPgR(void *p);
   static void destruct_vectorlEvectorlEfloatgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<vector<float> >*)
   {
      vector<vector<float> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<vector<float> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<vector<float> >", -2, "vector", 214,
                  typeid(vector<vector<float> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEvectorlEfloatgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<vector<float> >) );
      instance.SetNew(&new_vectorlEvectorlEfloatgRsPgR);
      instance.SetNewArray(&newArray_vectorlEvectorlEfloatgRsPgR);
      instance.SetDelete(&delete_vectorlEvectorlEfloatgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEvectorlEfloatgRsPgR);
      instance.SetDestructor(&destruct_vectorlEvectorlEfloatgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<vector<float> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<vector<float> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEvectorlEfloatgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<vector<float> >*)0x0)->GetClass();
      vectorlEvectorlEfloatgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEvectorlEfloatgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEvectorlEfloatgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<float> > : new vector<vector<float> >;
   }
   static void *newArray_vectorlEvectorlEfloatgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<vector<float> >[nElements] : new vector<vector<float> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEvectorlEfloatgRsPgR(void *p) {
      delete ((vector<vector<float> >*)p);
   }
   static void deleteArray_vectorlEvectorlEfloatgRsPgR(void *p) {
      delete [] ((vector<vector<float> >*)p);
   }
   static void destruct_vectorlEvectorlEfloatgRsPgR(void *p) {
      typedef vector<vector<float> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<vector<float> >

namespace ROOT {
   static TClass *vectorlEunsignedsPintgR_Dictionary();
   static void vectorlEunsignedsPintgR_TClassManip(TClass*);
   static void *new_vectorlEunsignedsPintgR(void *p = 0);
   static void *newArray_vectorlEunsignedsPintgR(Long_t size, void *p);
   static void delete_vectorlEunsignedsPintgR(void *p);
   static void deleteArray_vectorlEunsignedsPintgR(void *p);
   static void destruct_vectorlEunsignedsPintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<unsigned int>*)
   {
      vector<unsigned int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<unsigned int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<unsigned int>", -2, "vector", 214,
                  typeid(vector<unsigned int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEunsignedsPintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<unsigned int>) );
      instance.SetNew(&new_vectorlEunsignedsPintgR);
      instance.SetNewArray(&newArray_vectorlEunsignedsPintgR);
      instance.SetDelete(&delete_vectorlEunsignedsPintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEunsignedsPintgR);
      instance.SetDestructor(&destruct_vectorlEunsignedsPintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<unsigned int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<unsigned int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEunsignedsPintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<unsigned int>*)0x0)->GetClass();
      vectorlEunsignedsPintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEunsignedsPintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEunsignedsPintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<unsigned int> : new vector<unsigned int>;
   }
   static void *newArray_vectorlEunsignedsPintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<unsigned int>[nElements] : new vector<unsigned int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEunsignedsPintgR(void *p) {
      delete ((vector<unsigned int>*)p);
   }
   static void deleteArray_vectorlEunsignedsPintgR(void *p) {
      delete [] ((vector<unsigned int>*)p);
   }
   static void destruct_vectorlEunsignedsPintgR(void *p) {
      typedef vector<unsigned int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<unsigned int>

namespace ROOT {
   static TClass *vectorlEpairlEintcOintgRsPgR_Dictionary();
   static void vectorlEpairlEintcOintgRsPgR_TClassManip(TClass*);
   static void *new_vectorlEpairlEintcOintgRsPgR(void *p = 0);
   static void *newArray_vectorlEpairlEintcOintgRsPgR(Long_t size, void *p);
   static void delete_vectorlEpairlEintcOintgRsPgR(void *p);
   static void deleteArray_vectorlEpairlEintcOintgRsPgR(void *p);
   static void destruct_vectorlEpairlEintcOintgRsPgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<pair<int,int> >*)
   {
      vector<pair<int,int> > *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<pair<int,int> >));
      static ::ROOT::TGenericClassInfo 
         instance("vector<pair<int,int> >", -2, "vector", 214,
                  typeid(vector<pair<int,int> >), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEpairlEintcOintgRsPgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<pair<int,int> >) );
      instance.SetNew(&new_vectorlEpairlEintcOintgRsPgR);
      instance.SetNewArray(&newArray_vectorlEpairlEintcOintgRsPgR);
      instance.SetDelete(&delete_vectorlEpairlEintcOintgRsPgR);
      instance.SetDeleteArray(&deleteArray_vectorlEpairlEintcOintgRsPgR);
      instance.SetDestructor(&destruct_vectorlEpairlEintcOintgRsPgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<pair<int,int> > >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<pair<int,int> >*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEpairlEintcOintgRsPgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<pair<int,int> >*)0x0)->GetClass();
      vectorlEpairlEintcOintgRsPgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEpairlEintcOintgRsPgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEpairlEintcOintgRsPgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<pair<int,int> > : new vector<pair<int,int> >;
   }
   static void *newArray_vectorlEpairlEintcOintgRsPgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<pair<int,int> >[nElements] : new vector<pair<int,int> >[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEpairlEintcOintgRsPgR(void *p) {
      delete ((vector<pair<int,int> >*)p);
   }
   static void deleteArray_vectorlEpairlEintcOintgRsPgR(void *p) {
      delete [] ((vector<pair<int,int> >*)p);
   }
   static void destruct_vectorlEpairlEintcOintgRsPgR(void *p) {
      typedef vector<pair<int,int> > current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<pair<int,int> >

namespace ROOT {
   static TClass *vectorlEintgR_Dictionary();
   static void vectorlEintgR_TClassManip(TClass*);
   static void *new_vectorlEintgR(void *p = 0);
   static void *newArray_vectorlEintgR(Long_t size, void *p);
   static void delete_vectorlEintgR(void *p);
   static void deleteArray_vectorlEintgR(void *p);
   static void destruct_vectorlEintgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<int>*)
   {
      vector<int> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<int>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<int>", -2, "vector", 214,
                  typeid(vector<int>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEintgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<int>) );
      instance.SetNew(&new_vectorlEintgR);
      instance.SetNewArray(&newArray_vectorlEintgR);
      instance.SetDelete(&delete_vectorlEintgR);
      instance.SetDeleteArray(&deleteArray_vectorlEintgR);
      instance.SetDestructor(&destruct_vectorlEintgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<int> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<int>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEintgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<int>*)0x0)->GetClass();
      vectorlEintgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEintgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEintgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int> : new vector<int>;
   }
   static void *newArray_vectorlEintgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<int>[nElements] : new vector<int>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEintgR(void *p) {
      delete ((vector<int>*)p);
   }
   static void deleteArray_vectorlEintgR(void *p) {
      delete [] ((vector<int>*)p);
   }
   static void destruct_vectorlEintgR(void *p) {
      typedef vector<int> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<int>

namespace ROOT {
   static TClass *vectorlEfloatgR_Dictionary();
   static void vectorlEfloatgR_TClassManip(TClass*);
   static void *new_vectorlEfloatgR(void *p = 0);
   static void *newArray_vectorlEfloatgR(Long_t size, void *p);
   static void delete_vectorlEfloatgR(void *p);
   static void deleteArray_vectorlEfloatgR(void *p);
   static void destruct_vectorlEfloatgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<float>*)
   {
      vector<float> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<float>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<float>", -2, "vector", 214,
                  typeid(vector<float>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlEfloatgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<float>) );
      instance.SetNew(&new_vectorlEfloatgR);
      instance.SetNewArray(&newArray_vectorlEfloatgR);
      instance.SetDelete(&delete_vectorlEfloatgR);
      instance.SetDeleteArray(&deleteArray_vectorlEfloatgR);
      instance.SetDestructor(&destruct_vectorlEfloatgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<float> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<float>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlEfloatgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<float>*)0x0)->GetClass();
      vectorlEfloatgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlEfloatgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlEfloatgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<float> : new vector<float>;
   }
   static void *newArray_vectorlEfloatgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<float>[nElements] : new vector<float>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlEfloatgR(void *p) {
      delete ((vector<float>*)p);
   }
   static void deleteArray_vectorlEfloatgR(void *p) {
      delete [] ((vector<float>*)p);
   }
   static void destruct_vectorlEfloatgR(void *p) {
      typedef vector<float> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<float>

namespace ROOT {
   static TClass *vectorlETBranchmUgR_Dictionary();
   static void vectorlETBranchmUgR_TClassManip(TClass*);
   static void *new_vectorlETBranchmUgR(void *p = 0);
   static void *newArray_vectorlETBranchmUgR(Long_t size, void *p);
   static void delete_vectorlETBranchmUgR(void *p);
   static void deleteArray_vectorlETBranchmUgR(void *p);
   static void destruct_vectorlETBranchmUgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const vector<TBranch*>*)
   {
      vector<TBranch*> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(vector<TBranch*>));
      static ::ROOT::TGenericClassInfo 
         instance("vector<TBranch*>", -2, "vector", 214,
                  typeid(vector<TBranch*>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &vectorlETBranchmUgR_Dictionary, isa_proxy, 0,
                  sizeof(vector<TBranch*>) );
      instance.SetNew(&new_vectorlETBranchmUgR);
      instance.SetNewArray(&newArray_vectorlETBranchmUgR);
      instance.SetDelete(&delete_vectorlETBranchmUgR);
      instance.SetDeleteArray(&deleteArray_vectorlETBranchmUgR);
      instance.SetDestructor(&destruct_vectorlETBranchmUgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::Pushback< vector<TBranch*> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const vector<TBranch*>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *vectorlETBranchmUgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const vector<TBranch*>*)0x0)->GetClass();
      vectorlETBranchmUgR_TClassManip(theClass);
   return theClass;
   }

   static void vectorlETBranchmUgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_vectorlETBranchmUgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TBranch*> : new vector<TBranch*>;
   }
   static void *newArray_vectorlETBranchmUgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) vector<TBranch*>[nElements] : new vector<TBranch*>[nElements];
   }
   // Wrapper around operator delete
   static void delete_vectorlETBranchmUgR(void *p) {
      delete ((vector<TBranch*>*)p);
   }
   static void deleteArray_vectorlETBranchmUgR(void *p) {
      delete [] ((vector<TBranch*>*)p);
   }
   static void destruct_vectorlETBranchmUgR(void *p) {
      typedef vector<TBranch*> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class vector<TBranch*>

namespace ROOT {
   static TClass *maplEunsignedsPintcOevdcLcLboardSetgR_Dictionary();
   static void maplEunsignedsPintcOevdcLcLboardSetgR_TClassManip(TClass*);
   static void *new_maplEunsignedsPintcOevdcLcLboardSetgR(void *p = 0);
   static void *newArray_maplEunsignedsPintcOevdcLcLboardSetgR(Long_t size, void *p);
   static void delete_maplEunsignedsPintcOevdcLcLboardSetgR(void *p);
   static void deleteArray_maplEunsignedsPintcOevdcLcLboardSetgR(void *p);
   static void destruct_maplEunsignedsPintcOevdcLcLboardSetgR(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const map<unsigned int,evd::boardSet>*)
   {
      map<unsigned int,evd::boardSet> *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(map<unsigned int,evd::boardSet>));
      static ::ROOT::TGenericClassInfo 
         instance("map<unsigned int,evd::boardSet>", -2, "map", 96,
                  typeid(map<unsigned int,evd::boardSet>), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &maplEunsignedsPintcOevdcLcLboardSetgR_Dictionary, isa_proxy, 0,
                  sizeof(map<unsigned int,evd::boardSet>) );
      instance.SetNew(&new_maplEunsignedsPintcOevdcLcLboardSetgR);
      instance.SetNewArray(&newArray_maplEunsignedsPintcOevdcLcLboardSetgR);
      instance.SetDelete(&delete_maplEunsignedsPintcOevdcLcLboardSetgR);
      instance.SetDeleteArray(&deleteArray_maplEunsignedsPintcOevdcLcLboardSetgR);
      instance.SetDestructor(&destruct_maplEunsignedsPintcOevdcLcLboardSetgR);
      instance.AdoptCollectionProxyInfo(TCollectionProxyInfo::Generate(TCollectionProxyInfo::MapInsert< map<unsigned int,evd::boardSet> >()));
      return &instance;
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_(Init) = GenerateInitInstanceLocal((const map<unsigned int,evd::boardSet>*)0x0); R__UseDummy(_R__UNIQUE_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *maplEunsignedsPintcOevdcLcLboardSetgR_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const map<unsigned int,evd::boardSet>*)0x0)->GetClass();
      maplEunsignedsPintcOevdcLcLboardSetgR_TClassManip(theClass);
   return theClass;
   }

   static void maplEunsignedsPintcOevdcLcLboardSetgR_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_maplEunsignedsPintcOevdcLcLboardSetgR(void *p) {
      return  p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<unsigned int,evd::boardSet> : new map<unsigned int,evd::boardSet>;
   }
   static void *newArray_maplEunsignedsPintcOevdcLcLboardSetgR(Long_t nElements, void *p) {
      return p ? ::new((::ROOT::Internal::TOperatorNewHelper*)p) map<unsigned int,evd::boardSet>[nElements] : new map<unsigned int,evd::boardSet>[nElements];
   }
   // Wrapper around operator delete
   static void delete_maplEunsignedsPintcOevdcLcLboardSetgR(void *p) {
      delete ((map<unsigned int,evd::boardSet>*)p);
   }
   static void deleteArray_maplEunsignedsPintcOevdcLcLboardSetgR(void *p) {
      delete [] ((map<unsigned int,evd::boardSet>*)p);
   }
   static void destruct_maplEunsignedsPintcOevdcLcLboardSetgR(void *p) {
      typedef map<unsigned int,evd::boardSet> current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class map<unsigned int,evd::boardSet>

namespace {
  void TriggerDictionaryInitialization_libPixlar_Core_Impl() {
    static const char* headers[] = {
"GeoService.h",
"sparse_vector.h",
"RawBase.h",
"Point.h",
"Utils.h",
"ReadDQMFile.h",
0
    };
    static const char* includePaths[] = {
"/usr/include/python2.7",
"/usr/include/x86_64-linux-gnu/python2.7",
"/usr/local/lib/python2.7/dist-packages/numpy/core/include",
"/home/cadams/Software/ROOT/root6/include",
"/home/cadams/pixlar-evd/core/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "libPixlar_Core dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_Autoloading_Map;
namespace evd{class __attribute__((annotate("$clingAutoload$GeoService.h")))  GeoService;}
namespace evd{class __attribute__((annotate("$clingAutoload$RawBase.h")))  RawBase;}
namespace evd{class __attribute__((annotate("$clingAutoload$ReadDQMFile.h")))  ReadDQMFile;}
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "libPixlar_Core dictionary payload"

#ifndef G__VECTOR_HAS_CLASS_ITERATOR
  #define G__VECTOR_HAS_CLASS_ITERATOR 1
#endif

#define _BACKWARD_BACKWARD_WARNING_H
#include "GeoService.h"
#include "sparse_vector.h"
#include "RawBase.h"
#include "Point.h"
#include "Utils.h"
#include "ReadDQMFile.h"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[]={
"evd::GeoService", payloadCode, "@",
"evd::RawBase", payloadCode, "@",
"evd::ReadDQMFile", payloadCode, "@",
nullptr};

    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("libPixlar_Core",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_libPixlar_Core_Impl, {}, classesHeaders);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_libPixlar_Core_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_libPixlar_Core() {
  TriggerDictionaryInitialization_libPixlar_Core_Impl();
}
