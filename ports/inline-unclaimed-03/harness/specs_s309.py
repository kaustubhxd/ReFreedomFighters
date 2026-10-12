"""specs_s309.py - unclaimed-03 batch 9 (docs/20-unclaimed-03.md): CCheckInsideBox::Init (0x5b8120), thiscall with two
stack arguments (ret 8). Stubs in both runs, all patched per gen:
  * DBREAD operators, GetRefTab, REFTAB::Count, GetInput: serial_stubs.dbread_patch (the DBREAD u32 operator returns two
    random values in order);
  * global 0x70038c -> object M, slot +0xcc: 'mov eax,[esp+4]; mov [cell],eax; xor eax,K; ret 4' (records its argument,
    returns it xor K, so the two calls return different values);
  * object E at this+0x44, slot +0xbc: 'mov eax,[esp+4]; mov [cell2],eax; ret 4' (records its argument).
The DBREAD u32 operator is original code patched by dbread_patch; the port calls it through ext_4e5e60."""
from pilot import S

def _flush(c):
    """Stub code is written into the heap and the exe image at the same addresses each case. Drop Unicorn's translations
    for both so the new bytes run (see docs/20-unclaimed-20.md, harness note; added here, batch 11 review)."""
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)
import sys, os
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub(c, code):
    s = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(s, code)
    _flush(c)
    return s


def _gen(c):
    self_ = _rnd(c, 0x800)
    dbread = _rnd(c, 0x40)
    rets = [c.rng.getrandbits(32), c.rng.getrandbits(32)]
    ss.dbread_patch(c, rets, [0] * 8, [0] * 8)
    _flush(c)
    # The DBREAD u32 operator is re-patched to record ECX (the DBREAD object): mov [ecx_cell], ecx; eax = table[cnt];
    # cnt++; ret. Two random values in the table, in order. Without ECX, a read from the wrong DBREAD is not seen.
    ecx_cell, cnt = c.emu.alloc(4, 4), c.emu.alloc(4, 4)
    table = c.emu.alloc(8, 4)
    c.emu.w32(ecx_cell, 0)
    c.emu.w32(cnt, 0)
    c.emu.w32(table, rets[0])
    c.emu.w32(table + 4, rets[1])
    code = (b'\x89\x0d' + ecx_cell.to_bytes(4, 'little') +            # mov [ecx_cell], ecx
            b'\xa1' + cnt.to_bytes(4, 'little') +                     # mov eax, [cnt]
            b'\x8b\x04\x85' + table.to_bytes(4, 'little') +          # mov eax, [table + eax*4]
            b'\xff\x05' + cnt.to_bytes(4, 'little') +                 # inc dword [cnt]
            b'\xc3')
    ss.patch(c, ss.DBREAD_U32, _stub(c, code))
    _flush(c)
    # M at 0x70038c: slot +0xcc records its argument and returns it xor K
    K = c.rng.getrandbits(32)
    cell = c.emu.alloc(8, 4)
    c.emu.w32(cell, 0)
    m_code = (b'\x8b\x44\x24\x04\xa3' + cell.to_bytes(4, 'little') +
              b'\x35' + K.to_bytes(4, 'little') + b'\xc2\x04\x00')
    vt_m = c.emu.alloc(0x200, 4)
    c.emu.w32(vt_m + 0xcc, _stub(c, m_code))
    M = c.emu.alloc(0x40, 4)
    c.emu.w32(M, vt_m)
    c.emu.w32(0x70038c, M)
    # E at this+0x44: slot +0xbc records its argument
    cell2 = c.emu.alloc(8, 4)
    c.emu.w32(cell2, 0)
    e_code = b'\x8b\x44\x24\x04\xa3' + cell2.to_bytes(4, 'little') + b'\xc2\x04\x00'
    vt_e = c.emu.alloc(0x200, 4)
    c.emu.w32(vt_e + 0xbc, _stub(c, e_code))
    E = c.emu.alloc(0x40, 4)
    c.emu.w32(E, vt_e)
    c.emu.w32(self_ + 0x44, E)
    return [self_, c.rng.getrandbits(32), dbread]


S(0x5b8120, 'CCheckInsideBox::Init (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-03 batch 9; DBREAD via dbread_patch; stubs: global 0x70038c slot +0xcc, this+0x44 slot +0xbc')
