"""specs_s313.py - mounted gun batch 313: ZTankIf::SetTargetMachineGun, ZTankIf::FireMachineGun."""
from pilot import S
from mg_helpers import _rnd, _obj, flush, new_log, log_stub, make_block


def _gen(slot, nargs=1):
    def g(c):
        r = c.rng
        log = new_log(c)
        tank = _obj(c, 0x40, {slot: log_stub(c, log, slot, nargs)})
        s = _rnd(c, 0x40)
        c.emu.w32(s + 0x1c, tank)
        inb, _ = make_block(c, [(r.choice([0, 1, r.getrandbits(32)]), r.choice([0, 1]))], first=r.randint(0, 2))
        par = _rnd(c, 0x10)
        c.emu.w32(par + 4, inb)
        flush(c)
        return [s, par]
    return g


S(0x51b0e0, 'ZTankIf::SetTargetMachineGun', 'thiscall', None, gen=_gen(0x388), note='batch313')
S(0x5227f0, 'ZTankIf::FireMachineGun', 'thiscall', None, gen=_gen(0x38c), note='batch313')
S(0x522850, 'ZTankIf::SetTargetCannon', 'thiscall', None, gen=_gen(0x37c, 2), note='batch313')
S(0x5227c0, 'ZTankIf::FireCannon', 'thiscall', None, gen=_gen(0x380), note='batch313')
S(0x522910, 'ZTankIf::TurnToRef', 'thiscall', None, gen=_gen(0x374), note='batch313')
