import { DistrictsResponse, ProvincesResponse, SkolmatenStationsResponse } from "./types";
import performSkolmatenRequest from "./request";
import { ListSchools } from "../types";
import { School } from "../../types";

export function validateSchoolName(name: string): boolean {
	return !/info/i.test(name);
}

export const getSkolmatenSchools: ListSchools = async () => {
	const { provinces } = await performSkolmatenRequest<ProvincesResponse>("/provinces");

	const schools3d: School[][][] = await Promise.all(
		provinces.map(async (province) => {
			const { districts } = await performSkolmatenRequest<DistrictsResponse>(`/districts?province=${province.id}`);

			return Promise.all(
				districts.map(async (district) => {
					const { stations } = await performSkolmatenRequest<SkolmatenStationsResponse>(
						`/stations?district=${district.id}`,
					);

					return stations.map(({ id, name }) => ({
						id: id.toString(),
						name,
						district: district.name,
						province: province.name,
					}));
				}),
			);
		}),
	);

	const schools = schools3d.flat(2).filter(({ name }) => validateSchoolName(name));

	return schools;
};
