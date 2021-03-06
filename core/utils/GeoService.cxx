#ifndef GEOMETRYHELPER_CXX
#define GEOMETRYHELPER_CXX

#include "GeoService.h"

namespace pixevd {

GeoService* pixevd::GeoService::_me = 0;

GeoService::GeoService() {
  // Need to initialize the crazy mapping vector

  _lariat_channel_to_pixels.reserve(480);
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 232 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 231 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 230 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 229 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 228 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 227 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 226 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 225 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 240 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 239 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 238 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 237 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 236 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 235 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 234 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 233 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 216 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 215 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 214 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 213 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 212 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 211 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 210 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 209 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 224 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 223 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 222 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 221 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 220 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 219 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 218 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 217 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 200 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 199 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 198 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 197 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 196 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 195 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 194 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 193 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 208 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 207 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 206 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 205 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 204 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 203 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 202 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 201 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 169 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 170 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 171 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 172 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 173 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 174 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 175 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 176 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 161 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 162 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 163 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 164 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 165 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 166 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 167 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 168 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 137 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 138 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 139 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 140 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 141 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 142 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 143 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 144 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 129 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 130 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 131 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 132 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 133 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 134 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 135 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 136 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 234 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 235 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 236 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 237 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 238 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 239 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 240 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 211 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 212 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 213 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 214 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 215 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 216 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 217 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 218 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 219 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 206 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 207 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 208 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 209 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 210 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 181 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 182 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 183 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 184 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 185 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 186 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 187 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 188 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 189 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 190 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 191 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 178 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 179 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 180 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 151 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 152 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 153 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 154 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 155 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 156 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 157 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 158 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 159 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 160 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 161 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 162 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 163 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 150 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 121 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 122 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 123 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 124 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 125 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 126 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 127 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 128 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 129 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 130 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 131 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 132 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 133 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 134 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 135 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 120 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 119 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 118 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 117 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 116 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 115 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 114 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 113 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 112 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 111 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 110 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 109 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 108 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 107 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 106 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 105 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 88 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 87 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 86 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 85 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 84 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 83 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 82 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 81 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 80 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 79 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 78 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 77 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 76 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 75 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 74 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 73 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 56 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 55 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 54 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 53 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 52 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 51 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 50 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 49 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 48 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 47 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 46 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 45 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 44 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 43 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 42 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 41 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 24 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 23 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 22 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 21 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 20 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 19 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 18 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 17 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 16 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 15 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 14 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 13 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 12 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 11 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 10 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 9 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 112 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 111 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 110 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 109 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 108 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 107 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 106 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 105 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 104 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 103 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 102 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 101 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 100 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 99 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 98 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 97 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 80 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 79 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 78 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 77 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 76 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 75 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 74 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 73 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 72 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 71 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 70 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 69 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 68 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 67 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 66 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 65 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 185 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 186 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 187 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 188 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 189 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 190 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 191 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 192 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 177 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 178 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 179 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 180 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 181 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 182 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 183 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 184 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 153 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 154 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 155 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 156 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 157 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 158 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 159 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 160 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 145 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 146 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 147 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 148 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 149 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 150 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 151 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 152 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 121 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 122 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 123 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 124 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 125 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 126 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 127 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 128 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 226 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 227 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 228 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 229 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 230 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 231 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 232 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 233 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 220 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 221 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 222 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 223 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 224 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 225 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 196 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 197 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 198 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 199 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 200 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 201 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 202 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 203 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 204 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 205 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 192 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 193 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 194 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 195 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 166 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 167 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 168 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 169 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 170 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 171 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 172 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 173 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 174 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 175 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 176 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 177 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 164 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 165 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 136 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 137 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 138 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 139 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 140 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 141 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 142 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 143 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 144 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 145 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 146 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 147 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 148 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 149 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 104 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 103 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 102 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 101 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 100 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 99 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 98 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 97 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 96 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 95 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 94 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 93 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 92 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 91 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 90 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 89 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 72 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 71 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 70 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 69 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 68 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 67 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 66 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 65 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 64 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 63 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 62 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 61 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 60 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 59 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 58 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 57 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 40 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 39 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 38 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 37 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 36 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 35 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 34 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 33 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 32 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 31 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 30 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 29 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 28 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 27 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 26 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 25 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 8 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 7 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 6 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 5 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 4 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 3 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 2 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(1, 1 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 120 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 119 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 118 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 117 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 116 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 115 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 114 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 113 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 96 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 95 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 94 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 93 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 92 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 91 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 90 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 89 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 88 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 87 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 86 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 85 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 84 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 83 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 82 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 81 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 64 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 63 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 62 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 61 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 60 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 59 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 58 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 57 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 56 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 55 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 54 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 53 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 52 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 51 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 50 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 49 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 33 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 34 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 35 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 36 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 37 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 38 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 39 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 40 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 41 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 42 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 43 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 44 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 45 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 46 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 47 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 48 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 17 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 18 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 19 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 20 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 21 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 22 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 23 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 24 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 25 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 26 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 27 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 28 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 29 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 30 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 31 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 32 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 1 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 2 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 3 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 4 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 5 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 6 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 7 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 8 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 9 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 10 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 11 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 12 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 13 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 14 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 15 - 1));
  _lariat_channel_to_pixels.push_back(std::pair<int, int>(0, 16 - 1));

  // Invert the map:
  _pixel_to_lariat_channel.resize(2);
  _pixel_to_lariat_channel.at(0).resize(240);
  _pixel_to_lariat_channel.at(1).resize(240);
  for (size_t i = 0; i < _lariat_channel_to_pixels.size(); i++) {
    auto& pair = _lariat_channel_to_pixels.at(i);
    _pixel_to_lariat_channel.at(pair.first).at(pair.second) = i;
  }
}

bool GeoService::compatible(size_t pixel, size_t pad) const {
  if (pixel < 120) {
    if (pad < 120)
      return true;
    else
      return false;
  } else {
    if (pad < 120)
      return false;
    else
      return true;
  }
}

Point2D GeoService::xy(size_t pixel, size_t pad) const {
  if (compatible(pixel, pad))
    return pad_top_left(pad) + pixel_relative_coordinate(pixel);
  else
    throw pixlar_exception("Pixel and pad are not compatible!");
}

Point2D GeoService::pad_top_left(size_t pad) const {
  size_t pad_id = pad % 120;
  float shift = 0;
  if (pad > 120) shift = 36;
  float y_coord = pad_id % 15;
  float x_coord = pad_id / 15;
  return Point2D(x_coord * 4.5 + shift, y_coord * 2.4 - 18);
}

Point2D GeoService::pad_center(size_t pad) const {
  size_t pad_id = pad % 120;
  float shift = 0;
  if (pad > 120) shift = 36;
  float y_coord = pad_id % 15;
  float x_coord = pad_id / 15;
  return Point2D(x_coord * 4.5 + 2.25 + shift, y_coord * 2.4 + 1.2 - 18);
}

Point2D GeoService::pixel_relative_coordinate(size_t pixel) const {
  int y_coord = pixel % 8;
  int x_coord = pixel / 8;
  return Point2D(-x_coord * 0.3, y_coord * 0.3);
}

}  // pixevd`

#endif
