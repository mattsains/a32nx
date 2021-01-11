/*
 * A32NX
 * Copyright (C) 2020 FlyByWire Simulations and its contributors
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

import React, { useEffect, useState } from 'react';
import metarParser from 'aewx-metar-parser';
import { Metar as MetarClient } from '@flybywiresim/api-client';
import { IconWind } from '@tabler/icons';
import { IconGauge } from '@tabler/icons';
import { IconDroplet } from '@tabler/icons';
import { IconTemperature } from '@tabler/icons';
import { IconAccessPoint } from '@tabler/icons';
import { IconRouter } from '@tabler/icons';
import { IconPoint } from '@tabler/icons';

type Metar = {
    raw_text: string,
    raw_parts: [string],
    icao: string,
    observed: Date,
    wind: Wind,
    visibility: Visibility,
    conditions: [ConditionCode],
    clouds: [Cloud],
    ceiling: Ceiling,
    temperature: Temperature,
    dewpoint: Dewpoint,
    humidity_percent: number,
    barometer: Barometer,
    flight_category: string,
}

type Wind = {
    degrees: number,
    speed_kts: number,
    speed_mps: number,
    gust_kts: number,
    gust_mps: number,
};

type Visibility = {
    miles: string,
    miles_float: number,
    meters: string,
    meters_float: number,
};

type ConditionCode = {
    code: string,
};

type Cloud = {
    code: string,
    base_feet_agl: number,
    base_meters_agl: number,
};

type Ceiling = {
    code: string,
    feet_agl: number,
    meters_agl: number,
};

type Temperature = {
    celsius: number,
    fahrenheit: number,
};

type Dewpoint = {
    celsius: number,
    fahrenheit: number,
};

type Barometer = {
    hg: number,
    kpa: number,
    mb: number,
};

type WeatherWidgetProps = { name: string, icao?: string };

const WeatherWidget = (props: WeatherWidgetProps) => {
    const [enteredIcao, setEnteredIcao] = useState<string>('');
    const [metar, setMetar] = useState<Metar>();
    const [modalStatus, setModalStatus] = useState(false);

    // This could be modified using the Settings tab perhaps?
    const source = "vatsim";

    const handleIcao = (event: { target: { value: React.SetStateAction<string>; }; }) => {
        setEnteredIcao(event.target.value);
        if (event.target.value.length === 4) {
            getMetar(event.target.value, source);
        } else if (event.target.value.length === 0) {
            getMetar(props.icao, source);
        }
    };

    async function getMetar(icao:any, source: any) {
        if (icao) {
            try {
                const result = await MetarClient.get(icao, source);
                const metarParse = metarParser(result.metar);
                console.info(metarParse);
                setEnteredIcao(icao);
                setMetar(metarParse);
            } catch (e) {
                setMetar(undefined);
            }
        }
    }

    useEffect(() => {
        getMetar(props.icao, source);
    }, [props.icao]);

    function showModal() {
        setModalStatus(!modalStatus);
    }

    return (
        <div className="bg-gray-800 rounded-xl p-6 text-white mb-4 shadow-lg" id={'weather-card-' + props.name}>
            {<><div className="mb-6">
                    <div className="flex items-center">
                        {<>
                                <IconAccessPoint className="absolute" size={35} stroke={1.5} strokeLinejoin="miter" />
                                <input className="ml-12 border-none focus:outline-none text-2xl bg-transparent font-medium uppercase"
                                    type="text"
                                    placeholder={props.icao ?? '----'}
                                    value={enteredIcao}
                                    onChange={handleIcao} />
                        </>
                        }
                    </div>
                </div>
                <div className="mb-6">
                    <div className="grid grid-cols-2">
                        <div className="text-center text-lg">
                            <div className="flex justify-center">
                                <IconGauge className="mb-2" size={35} stroke={1.5} strokeLinejoin="miter" />
                            </div>
                            {metar?.barometer.mb.toFixed(0) ?? '???'} mb
                        </div>
                        <div className="text-center text-lg">
                            <div className="flex justify-center">
                                <IconWind className="mb-2" size={35} stroke={1.5} strokeLinejoin="miter" />
                            </div>
                            {metar?.wind.degrees.toFixed(0) ?? '???'}° / {metar?.wind.speed_kts.toFixed(0) ?? '???'} kts
                        </div>
                        <div className="text-center text-lg mt-3">
                            <div className="flex justify-center">
                                <IconTemperature className="mb-2" size={35} stroke={1.5} strokeLinejoin="miter" />
                            </div>
                            {metar?.temperature.celsius.toFixed(0) ?? '???'} °C
                        </div>
                        <div className="text-center text-lg mt-3">
                            <div className="flex justify-center">
                                <IconDroplet className="mb-2" size={35} stroke={1.5} strokeLinejoin="miter" />
                            </div>
                            {metar?.dewpoint.celsius.toFixed(0) ?? '???'} °C
                        </div>
                    </div>
                </div>
                <div className="font-medium leading-7">
                    <IconRouter className="mr-2 inline-block" size={23} stroke={1.5} strokeLinejoin="miter" /> {metar?.raw_text ?? 'No METAR Available'}
                </div>
                </>
            }
        </div>
    );
};

export default WeatherWidget;
