"""specs_s6302.py - unclaimed-63 batch 2 (docs/20-unclaimed-63.md): LINKREFTAB::ClearThis (0x4cdc60) and Clear (0x4cdb20), thiscall
with no arguments. Stubs, rewritten each case (with a translation flush):
  * this+0x24 is an object (or 0) whose slot 0 records its argument (the deleting flag) and returns;
  * this's vtable slot +0x7c records its argument (a list node) into a ring of four heap cells, indexed by its call count;
  * the list at this+4 is 0 to 3 random nodes, each node's +4 pointing to the next (the last one is 0)."""
from pilot import S
import sys, os
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cell(c, n=1):
    a = c.emu.alloc(4 * n, 4)
    c.emu.wbytes(a, bytes(4 * n))
    return a


def _le(v):
    return v.to_bytes(4, 'little')


def _flush(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    _flush(c)
    return s


def _gen_common(c, with_list):
    self_ = _rnd(c, 0x100)
    vt = c.emu.alloc(0x400, 4)
    # obj at +0x24: slot 0 records arg 1 (ret 4)
    cobj = _cell(c)
    o = _rnd(c, 0x40)
    vt_o = c.emu.alloc(0x100, 4)
    c.emu.w32(vt_o, _stub(c, b'\x8b\x44\x24\x04\xa3' + _le(cobj) + b'\xc2\x04\x00'))
    c.emu.w32(o, vt_o)
    use_obj = c.rng.random() < 0.7
    c.emu.w32(self_ + 0x24, o if use_obj else 0)
    if with_list:
        cnt = _cell(c)
        ring = _cell(c, 4)
        # vtbl +0x7c: ring[cnt] = arg 1; cnt++; ret 4
        # the callee overwrites the node's next pointer with garbage, so a port that reads next after the call fails
        garbage = c.rng.getrandbits(32) | 1
        code = (b'\x8b\x44\x24\x04' + b'\x8b\x15' + _le(cnt) + b'\x89\x04\x95' + _le(ring) +
                b'\xc7\x40\x04' + _le(garbage) +                       # mov dword [eax+4], garbage
                b'\xff\x05' + _le(cnt) + b'\xc2\x04\x00')
        c.emu.w32(vt + 0x7c, _stub(c, code))
        nodes = [_rnd(c, 0x40) for _ in range(c.rng.randint(0, 3))]
        for i, nd in enumerate(nodes):
            c.emu.w32(nd + 4, nodes[i + 1] if i + 1 < len(nodes) else 0)
        c.emu.w32(self_ + 4, nodes[0] if nodes else 0)
    c.emu.w32(self_, vt)
    return [self_]


def _gen_ct(c):
    return _gen_common(c, False)


def _gen_clear(c):
    return _gen_common(c, True)


S(0x4cdc60, 'LINKREFTAB::ClearThis (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_ct,
  note='unclaimed-63 batch 2; obj at +0x24 slot 0 stub')
S(0x4cdb20, 'LINKREFTAB::Clear (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_clear,
  note='unclaimed-63 batch 2; obj at +0x24 slot 0 stub; list walk via vtbl+0x7c stub')
