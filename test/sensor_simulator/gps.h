/****************************************************************************
 *
 *   Copyright (c) 2019 ECL Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * Feeds Ekf with Gps data
 * @author Kamil Ritz <ka.ritz@hotmail.com>
 */
#pragma once

#include "sensor.h"

namespace sensor_simulator
{
namespace sensor
{

class Gps: public Sensor
{
public:
	Gps(std::shared_ptr<Ekf> ekf);
	~Gps();

	void setData(const gps_message& gps);
	void stepHeightByMeters(float hgt_change);
	void stepHorizontalPositionByMeters(Vector2f hpos_change);
	void setPositionRateNED(const Vector3f& rate) { _gps_pos_rate = rate; }
	void setAltitude(int32_t alt);
	void setLatitude(int32_t lat);
	void setLongitude(int32_t lon);
	void setVelocity(const Vector3f& vel);
	void setYaw(float yaw);
	void setFixType(int n);
	void setNumberOfSatellites(int n);
	void setPdop(float pdop);

	gps_message getDefaultGpsData();

private:
	gps_message _gps_data{};
	Vector3f _gps_pos_rate{};

	void send(uint64_t time) override;

};

} // namespace sensor
} // namespace sensor_simulator
