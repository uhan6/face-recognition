#include "proj_com.h"


namespace project_common {

	mutex COM_MTX;

	Com* Com::_instance = NULL;


	Com::Com() {

		this->SERIALIZATION_PATH = "D:\\opencv_faces_ocv\\common.xml";
		this->FACES_FOLDER = "D:\\opencv_faces_ocv\\";
		this->CASCADE_PATH = "res\haarcascade_frontalface_alt.xml";
		this->LBPH_PCT = 70.00;

		this->_int_num = 0;
	}


	// Com 类中成员、变量初始化
	Com* Com::INS() {
		if (Com::_instance == NULL) {

			COM_MTX.lock();
			if (Com::_instance == NULL) {
				Com::_instance = new Com();
			}
			COM_MTX.unlock();

		}
		return Com::_instance;
	}


	int Com::serialization() {
		// 使用tinyxml2储存
		XMLDocument doc;
		XMLElement *root, *ele, *xml_pair, *key, *val;

		doc.InsertEndChild(doc.NewDeclaration("xml version=\"1.0\" encoding=\"gbk\""));
		doc.InsertEndChild(doc.NewComment("序列化存储 Com 类"));
		root = doc.NewElement("Com");

		ele = doc.NewElement("serial_path");
		ele->InsertEndChild(doc.NewText((this->SERIALIZATION_PATH).c_str()));
		root->InsertEndChild(ele);

		ele = doc.NewElement("face_folder");
		ele->InsertEndChild(doc.NewText((this->FACES_FOLDER).c_str()));
		root->InsertEndChild(ele);

		ele = doc.NewElement("cascade_path");
		ele->InsertEndChild(doc.NewText(this->CASCADE_PATH.c_str()));
		root->InsertEndChild(ele);

		ele = doc.NewElement("lbph_pct");
		ele->InsertEndChild(doc.NewText(to_string(this->LBPH_PCT).c_str()));
		root->InsertEndChild(ele);

		ele = doc.NewElement("num");
		ele->InsertEndChild(doc.NewText(to_string(this->_int_num).c_str()));
		root->InsertEndChild(ele);




		// 遍历 id_name map
		ele = doc.NewElement("id_name");
		map<int, string>::iterator id_name_iter;

		for (id_name_iter = _map_id_name.begin(); id_name_iter != _map_id_name.end(); id_name_iter++) {
			xml_pair = doc.NewElement("id_name_pair");

			key = doc.NewElement("id");
			key->InsertEndChild(doc.NewText(to_string(id_name_iter->first).c_str()));
			val = doc.NewElement("name");
			val->InsertEndChild(doc.NewText((id_name_iter->second).c_str()));

			xml_pair->InsertEndChild(key);
			xml_pair->InsertEndChild(val);
			ele->InsertEndChild(xml_pair);
		}
		root->InsertEndChild(ele);


		// 遍历 name_index map
		ele = doc.NewElement("name_index");
		map<string, int>::iterator name_index_iter;

		for (name_index_iter = _map_name_index.begin(); name_index_iter != _map_name_index.end(); name_index_iter++) {
			xml_pair = doc.NewElement("name_index_pair");

			key = doc.NewElement("name");
			key->InsertEndChild(doc.NewText((name_index_iter->first).c_str()));
			val = doc.NewElement("index");
			val->InsertEndChild(doc.NewText(to_string(name_index_iter->second).c_str()));

			xml_pair->InsertEndChild(key);
			xml_pair->InsertEndChild(val);
			ele->InsertEndChild(xml_pair);
		}
		root->InsertEndChild(ele);


		// 遍历 images_labels vector
		ele = doc.NewElement("images_labels");

		for (int i = 0; i < _vct_images_labels.size(); i++) {
			xml_pair = doc.NewElement("images_labels_pair");

			xml_pair->InsertEndChild(doc.NewText((_vct_images_labels[i]).c_str()));

			ele->InsertEndChild(xml_pair);
		}
		root->InsertEndChild(ele);

		doc.InsertEndChild(root);

		int flag = doc.SaveFile(Com::SERIALIZATION_PATH.c_str());

		if (flag != 0) {
			cerr << "序列化失败！" << endl;
			return 0;
		}
		return 1;
	}


	int Com::un_serialization() {
		XMLDocument doc;
		doc.LoadFile(Com::SERIALIZATION_PATH.c_str());

		if (doc.ErrorID() != 0) {
			cerr << "反序列化加载失败！" << endl;
			return 0;
		}

		XMLElement *root, *ele, *xml_pair;

		root = doc.FirstChildElement("Com");

		ele = root->FirstChildElement("serial_path");
		this->SERIALIZATION_PATH = ele->GetText();

		ele = root->FirstChildElement("face_folder");
		this->FACES_FOLDER = ele->GetText();

		ele = root->FirstChildElement("cascade_path");
		this->CASCADE_PATH = ele->GetText();

		ele = root->FirstChildElement("lbph_pct");
		this->LBPH_PCT = atof(ele->GetText());

		ele = root->FirstChildElement("num");
		this->_int_num = atoi(ele->GetText());

		// id_name
		ele = root->FirstChildElement("id_name");
		xml_pair = ele->FirstChildElement("id_name_pair");
		while (NULL != xml_pair) {
			int id = atoi(xml_pair->FirstChildElement("id")->GetText());
			string name = xml_pair->FirstChildElement("name")->GetText();
			this->_map_id_name.insert(pair<int, string>(id, name));
			xml_pair = xml_pair->NextSiblingElement();
		}

		// name_index
		ele = root->FirstChildElement("name_index");
		xml_pair = ele->FirstChildElement("name_index_pair");
		while (NULL != xml_pair) {
			string name = xml_pair->FirstChildElement("name")->GetText();
			int index = atoi(xml_pair->FirstChildElement("index")->GetText());
			this->_map_name_index.insert(pair<string, int>(name, index));
			xml_pair = xml_pair->NextSiblingElement();
		}

		// images_labels
		ele = root->FirstChildElement("images_labels");
		xml_pair = ele->FirstChildElement("images_labels_pair");
		while (NULL != xml_pair) {
			string str_images_labels = xml_pair->GetText();
			this->_vct_images_labels.push_back(str_images_labels);
			xml_pair = xml_pair->NextSiblingElement();
		}

		return 1;
	}


	int Com::get_num() {
		return this->_int_num;
	}


	void Com::set_num(int num) {
		this->_int_num = num;
	}


	int Com::get_id(string name) {
		map<int, string>::iterator _iter;

		for (_iter = _map_id_name.begin(); _iter != _map_id_name.end(); _iter++) {
			if (_iter->second == name) {
				return _iter->first;
			}
		}
		return -1;
	}


	string Com::get_name(int id) {
		map<int, string>::iterator _iter;

		for (_iter = _map_id_name.begin(); _iter != _map_id_name.end(); _iter++) {
			if (_iter->first == id) {
				return _iter->second;
			}
		}
		return NULL;
	}


	int Com::get_index(string name) {
		map<string, int>::iterator _iter;

		for (_iter = _map_name_index.begin(); _iter != _map_name_index.end(); _iter++) {
			if (_iter->first == name) {
				return _iter->second;
			}
		}
		return 0;
	}


	int Com::set_index(string name, int index) {
		map<string, int>::iterator _iter;

		for (_iter = _map_name_index.begin(); _iter != _map_name_index.end(); _iter++) {
			if (_iter->first == name) {
				_iter->second = index;
				return 1;
			}
		}
		return 0;
	}


	int Com::is_exist_name(string name) {
		map<int, string>::iterator _iter;

		for (_iter = _map_id_name.begin(); _iter != _map_id_name.end(); _iter++) {
			if (_iter->second == name) {
				return 1;
			}
		}
		return 0;
	}


	int Com::is_exist_id(int id) {
		map<int, string>::iterator _iter;

		for (_iter = _map_id_name.begin(); _iter != _map_id_name.end(); _iter++) {
			if (_iter->first == id) {
				return 1;
			}
		}
		return 0;
	}


	map<int, string>& Com::get_id_name() {
		return this->_map_id_name;
	}


	map<string, int>& Com::get_name_index() {
		return this->_map_name_index;
	}


	vector<string>& Com::get_img_lb() {
		return this->_vct_images_labels;
	}


}