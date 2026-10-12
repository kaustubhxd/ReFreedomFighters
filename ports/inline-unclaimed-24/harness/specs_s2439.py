"""specs_s2439.py - decomp area 24, batch 2439 (gap band): five tail-jump forwarders. Targets are recorders:
0x4db930 ZBaseGeom::HideRecursive(bool), 0x4dceb0 ZBaseGeom::SetRootPos, 0x4dcf80 ZBaseGeom::SetRootTM (two arguments),
0x43f900 ZGROUP::CopyDataBlock(DBLK*). The object at +8 (or at +0x5c for the material group) is the forwarder's ecx."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks


def _geom_arg(addr, nargs_extra):
    def gen(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu
        geom = rnd(c, 0x80)
        o = rnd(c, 0x40)
        e.w32(o + 8, geom)
        hook_rec(c, addr, nargs_extra, this=True)
        args = [o]
        if nargs_extra == 1:
            args.append(r.getrandbits(32) if addr == 0x4db930 else rnd(c, 0x20))
        else:
            args += [rnd(c, 0x20), rnd(c, 0x20)]
        return args
    return gen


def _blk(c):
    clear_hooks(c)
    o = rnd(c, 0x40)
    hook_rec(c, 0x43f900, 1, this=True)
    return [o, rnd(c, 0x40)]


def _mat(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x80)
    t = obj(c, 0x40, {4: pystub(c, 1)})
    e.w32(o + 0x5c, t)
    return [o, rnd(c, 0x20)]


S(0x45f080, 'ZGEOM::HideRecursive', 'thiscall', None, ret=None, gen=_geom_arg(0x4db930, 1), note='batch2439')
S(0x45fd30, 'ZGEOM::SetRootPos', 'thiscall', None, ret=None, gen=_geom_arg(0x4dceb0, 1), note='batch2439')
S(0x45fd40, 'ZGEOM::SetRootTM', 'thiscall', None, ret=None, gen=_geom_arg(0x4dcf80, 2), note='batch2439')
S(0x454910, 'ZTemplate::CopyDataBlock', 'thiscall', None, ret='eax', gen=_blk, note='batch2439')
S(0x454b50, 'ZMaterialDescGroup::AddMaterialDescriptor', 'thiscall', None, ret=None, gen=_mat, note='batch2439')
