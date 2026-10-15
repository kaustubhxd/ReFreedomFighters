"""specs_s923.py - vehicles batch 923: car sounds, scramble, special states, CalcTurnAngle."""
from pilot import S
from vh import _rnd, _stub, obj, r32, rf
import specs_s907 as b907


def g_snd(c):
    s = _rnd(c, 0x1b00)
    c.emu.w32(s + 0x1a9f, 0 if c.rng.random() < 0.2 else obj(c, 0x10, {0x60: _stub(c, 2, ret=r32(c))}))
    c.emu.w32(0x70039c, s)
    return [obj(c, 0x200, {0x2e8: _stub(c, 1, ret=r32(c))})]


for a, n in ((0x518750, 'ZCar::SoundAirBreak'), (0x518790, 'ZCar/ZTank::SoundEngineStart'),
             (0x5187d0, 'ZCar/ZTank::SoundEngineStop'), (0x518810, 'ZCar::SoundGearShift'),
             (0x5217f0, 'ZCar/ZTank::SoundSpeedUp')):
    S(a, n, 'thiscall', ret='eax', gen=g_snd)

S(0x5186d0, 'ZCar::SetSoundScramble', 'thiscall',
  gen=lambda c: [_rnd(c, 0x1700), c.rng.choice([0, rf(c, -40, 10)]), rf(c), r32(c)])
S(0x522f60, 'CMoveAlongPath::CalcTurnAngle', 'thiscall', ret='st0',
  gen=lambda c: [b907.path(c), rf(c, 0, 1), rf(c, 0, 600)])


def g_ss(c):
    car = _rnd(c, 0x1700)
    p = b907.path(c)
    c.emu.w32(p + 0x24, rf(c, 0, 1000))
    c.emu.w32(car + 0x5c, p)
    c.emu.w32(car + 0x358, c.rng.choice([0, rf(c)]))
    return [car]


S(0x519280, 'ZCar::UpdateSpecialStates', 'thiscall', gen=g_ss)
